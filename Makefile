CC     =  clang
CFLAGS =  -std=c17 -Wall -Wextra -Wpedantic -Iinclude -march=native -mtune=native -O3 -fPIC
ifneq ($(thrdsafe),0)
CFLAGS += -Du8c_bethrdsafe
endif
ifeq ($(debug),1)
CFLAGS += -g
else
CFLAGS += -DNDEBUG
endif
LDFLAGS = -shared -lpthread
SRCS = \
	src/u8c/debug.c \
	src/u8c/end.c \
	src/u8c/err.c \
	src/u8c/errlock.c \
	src/u8c/fmt.c \
	src/u8c/geterr.c \
	src/u8c/init.c \
	src/u8c/isalnum.c \
	src/u8c/isalpha.c \
	src/u8c/iscntrl.c \
	src/u8c/isdigit.c \
	src/u8c/isspace.c \
	src/u8c/ispunct.c \
	src/u8c/print.c \
	src/u8c/println.c \
	src/u8c/seterr.c \
	src/u8c/stat.c \
	src/u8c/thrdsafe.c \
	src/u8c/u32cmp.c \
	src/u8c/u32cp.c \
	src/u8c/u32sz.c \
	src/u8c/u8dec.c \
	src/u8c/u8enc.c \
	src/u8c/vfmt.c \
	src/u8c/vprint.c
HDRS = \
	include/u8c/col.h \
	include/u8c/dbgprint.h \
	include/u8c/debug.h \
	include/u8c/end.h \
	include/u8c/fmt.h \
	include/u8c/fmttyp.h \
	include/u8c/geterr.h \
	include/u8c/init.h \
	include/u8c/isalnum.h \
	include/u8c/isalpha.h \
	include/u8c/iscntrl.h \
	include/u8c/isdigit.h \
	include/u8c/isspace.h \
	include/u8c/ispunct.h \
	include/u8c/print.h \
	include/u8c/println.h \
	include/u8c/seterr.h \
	include/u8c/SIZE_C.h \
	include/u8c/thrdsafe.h \
	include/u8c/txt.h \
	include/u8c/u32cmp.h \
	include/u8c/u32cp.h \
	include/u8c/u32free.h \
	include/u8c/u32sz.h \
	include/u8c/u8dec.h \
	include/u8c/u8enc.h \
	include/u8c/u8free.h \
	include/u8c/ver.h \
	include/u8c/vfmt.h \
	include/u8c/vprint.h
HDRS_PRIV = \
	src/u8c/err.h \
	src/u8c/errlock.h \
	src/u8c/stat.h
OBJS = $(SRCS:.c=.o)
LIB  = libu8c.so
$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJS): $(HDRS) $(HDRS_PRIV)
.PHONY: clean install purge runtest uninstall
clean:
	rm --force $(OBJS)
install: $(LIB)
	mkdir --parents $(DESTDIR)/include/u8c
	mkdir --parents $(DESTDIR)/lib
	install --mode=444 $(HDRS) $(DESTDIR)/include/u8c
	install --mode=555 $(LIB) $(DESTDIR)/lib
purge:
	rm --force test txttolit $(LIB) $(OBJS)
runtest: test
	export LD_LIBRARY_PATH=$(CURDIR) && ./$^
test: $(LIB) test.c
	$(CC) -std=c17 -Wall -Wextra -Wpedantic -Iinclude -march=native -mtune=native -O3 -g -L. -lu8c -o $@ $@.c
txttolit: $(LIB) txttolit.c
	$(CC) -std=c17 -Wall -Wextra -Wpedantic -Iinclude -march=native -mtune=native -O3 -g -L. -lu8c -o $@ $@.c
	export LD_LIBRARY_PATH=$(CURDIR) && ./$@
uninstall:
	rm --force --recursive $(DESTDIR)/include/u8c/
	rm --force --recursive $(DESTDIR)/lib/$(LIB)

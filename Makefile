CC     =  clang
CFLAGS =  -std=c17 -Wall -Wextra -pedantic-errors -Iinclude -march=native -mtune=native -fPIC
ifneq ($(thrdsafe),0)
CFLAGS += -Du8c_bethrdsafe
endif
ifeq ($(debug),1)
CFLAGS += -g
else
CFLAGS += -O3 -DNDEBUG
endif
LDFLAGS = -shared -lpthread
HDRS = \
	include/u8c/SIZE_C.h \
	include/u8c/abrt.h \
	include/u8c/col.h \
	include/u8c/dbg.h \
	include/u8c/dbgprint.h \
	include/u8c/end.h \
	include/u8c/fmt.h \
	include/u8c/fmttyp.h \
	include/u8c/geterr.h \
	include/u8c/init.h \
	include/u8c/isalnum.h \
	include/u8c/isalpha.h \
	include/u8c/iscntrl.h \
	include/u8c/isdigit.h \
	include/u8c/ispunct.h \
	include/u8c/isspace.h \
	include/u8c/isxdigit.h \
	include/u8c/print.h \
	include/u8c/println.h \
	include/u8c/seterr.h \
	include/u8c/setfmt.h \
	include/u8c/thrdsafe.h \
	include/u8c/u32alloc.h \
	include/u8c/u32cat.h \
	include/u8c/u32cmp.h \
	include/u8c/u32cp.h \
	include/u8c/u32fndchr.h \
	include/u8c/u32fndpat.h \
	include/u8c/u32free.h \
	include/u8c/u32substr.h \
	include/u8c/u32sz.h \
	include/u8c/u8alloc.h \
	include/u8c/u8dec.h \
	include/u8c/u8enc.h \
	include/u8c/u8free.h \
	include/u8c/unimax.h \
	include/u8c/ver.h \
	include/u8c/vfmt.h \
	include/u8c/vprint.h
HDRS_PRIV = \
	src/u8c/dat.h \
	src/u8c/dattyp.h
SRCS = \
	src/u8c/abrt.c \
	src/u8c/dat.c \
	src/u8c/debug.c \
	src/u8c/end.c \
	src/u8c/fmt.c \
	src/u8c/geterr.c \
	src/u8c/init.c \
	src/u8c/isalnum.c \
	src/u8c/isalpha.c \
	src/u8c/iscntrl.c \
	src/u8c/isdigit.c \
	src/u8c/isspace.c \
	src/u8c/ispunct.c \
	src/u8c/isxdigit.c \
	src/u8c/print.c \
	src/u8c/println.c \
	src/u8c/seterr.c \
	src/u8c/setfmt.c \
	src/u8c/thrdsafe.c \
	src/u8c/u32alloc.c \
	src/u8c/u32cat.c \
	src/u8c/u32cmp.c \
	src/u8c/u32cp.c \
	src/u8c/u32fndchr.c \
	src/u8c/u32fndpat.c \
	src/u8c/u32free.c \
	src/u8c/u32substr.c \
	src/u8c/u32sz.c \
	src/u8c/u8alloc.c \
	src/u8c/u8dec.c \
	src/u8c/u8enc.c \
	src/u8c/u8free.c \
	src/u8c/vfmt.c \
	src/u8c/vprint.c
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
uninstall:
	rm --force --recursive $(DESTDIR)/include/u8c/
	rm --force --recursive $(DESTDIR)/lib/$(LIB)

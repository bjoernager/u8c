CC      =  clang
CFLAGS  =  -std=c17 -Weverything -Wno-c99-compat -Wno-format-nonliteral -Wpedantic -Iinclude -march=native -mtune=native -O3
CFLAGS0 =  $(CFLAGS) -g -L. -lu8c -o $@ $^
CFLAGS  += -fPIC
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
	src/u8c/print.c \
	src/u8c/println.c \
	src/u8c/seterr.c \
	src/u8c/stat.c \
	src/u8c/thrdsafe.c \
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
	include/u8c/print.h \
	include/u8c/println.h \
	include/u8c/SIZE_C.h \
	include/u8c/thrdsafe.h \
	include/u8c/u32cp.h \
	include/u8c/u32sz.h \
	include/u8c/u8dec.h \
	include/u8c/u8enc.h \
	include/u8c/ver.h \
	include/u8c/vfmt.h \
	include/u8c/vprint.h
HDRS_PRIV = \
	src/u8c/err.h \
	src/u8c/errlock.h \
	src/u8c/seterr.h \
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
	$(CC) $(CFLAGS0)
txttolit: $(LIB) txttolit.c
	$(CC) $(CFLAGS0)
	export LD_LIBRARY_PATH=$(CURDIR) && ./$@
uninstall:
	rm --force --recursive $(DESTDIR)/include/u8c/
	rm --force --recursive $(DESTDIR)/lib/$(LIB)

CC     =  gcc
CFLAGS =  -std=c2x -Wall -Wextra -Wmissing-prototypes -pedantic-errors -Iinclude -fPIC
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
	include/u8c/err.h    \
	include/u8c/fmt.h    \
	include/u8c/is.h     \
	include/u8c/main.h   \
	include/u8c/SIZE_C.h \
	include/u8c/u16.h    \
	include/u8c/u32.h    \
	include/u8c/u8.h
HDRS_PRIV = \
	include/u8c/intern.h
SRCS = \
	src/u8c/err.h.d/geterr.c      \
	src/u8c/err.h.d/regerrhandl.c \
	src/u8c/err.h.d/seterr.c      \
	src/u8c/fmt.h.d/fmt.c         \
	src/u8c/fmt.h.d/print.c       \
	src/u8c/fmt.h.d/println.c     \
	src/u8c/fmt.h.d/setfmt.c      \
	src/u8c/fmt.h.d/vfmt.c        \
	src/u8c/fmt.h.d/vprint.c      \
	src/u8c/intern.h.d/dat.c      \
	src/u8c/is.h.d/isalnum.c      \
	src/u8c/is.h.d/isalpha.c      \
	src/u8c/is.h.d/iscntrl.c      \
	src/u8c/is.h.d/isdigit.c      \
	src/u8c/is.h.d/ispunct.c      \
	src/u8c/is.h.d/isspace.c      \
	src/u8c/is.h.d/isxdigit.c     \
	src/u8c/main.h.d/abrtfn.c     \
	src/u8c/main.h.d/debug.c      \
	src/u8c/main.h.d/end.c        \
	src/u8c/main.h.d/init.c       \
	src/u8c/main.h.d/thrdsafe.c   \
	src/u8c/u8.h.d/u8alloc.c      \
	src/u8c/u8.h.d/u8dec.c        \
	src/u8c/u8.h.d/u8enc.c        \
	src/u8c/u8.h.d/u8free.c       \
	src/u8c/u16.h.d/u16alloc.c    \
	src/u8c/u16.h.d/u16free.c     \
	src/u8c/u32.h.d/u32alloc.c    \
	src/u8c/u32.h.d/u32cat.c      \
	src/u8c/u32.h.d/u32cmp.c      \
	src/u8c/u32.h.d/u32cp.c       \
	src/u8c/u32.h.d/u32fndchr.c   \
	src/u8c/u32.h.d/u32fndpat.c   \
	src/u8c/u32.h.d/u32free.c     \
	src/u8c/u32.h.d/u32ins.c      \
	src/u8c/u32.h.d/u32substr.c   \
	src/u8c/u32.h.d/u32sz.c
OBJS = $(SRCS:.c=.o)
LIB  = libu8c.so
$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJS): $(HDRS) $(HDRS_PRIV)
DOCS = \
	docs/u8c_abrt.3.gz        \
	docs/u8c_abrtfn.3.gz      \
	docs/u8c_col.3.gz         \
	docs/u8c_dbg.3.gz         \
	docs/u8c_dbgprint.3.gz    \
	docs/u8c_end.3.gz         \
	docs/u8c_errhandltyp.3.gz \
	docs/u8c_errtyp.3.gz      \
	docs/u8c_fmt.3.gz         \
	docs/u8c_fmttyp.3.gz      \
	docs/u8c_geterr.3.gz      \
	docs/u8c_init.3.gz        \
	docs/u8c_isalnum.3.gz     \
	docs/u8c_isalpha.3.gz     \
	docs/u8c_iscntrl.3.gz     \
	docs/u8c_isdigit.3.gz     \
	docs/u8c_ispunct.3.gz     \
	docs/u8c_isspace.3.gz     \
	docs/u8c_isxdigit.3.gz    \
	docs/u8c_print.3.gz       \
	docs/u8c_println.3.gz     \
	docs/u8c_regerrhandl.3.gz \
	docs/u8c_seterr.3.gz      \
	docs/u8c_setfmt.3.gz      \
	docs/u8c_thrdsafe.3.gz    \
	docs/u8c_u8alloc.3.gz     \
	docs/u8c_u8dec.3.gz       \
	docs/u8c_u8enc.3.gz       \
	docs/u8c_u8free.3.gz      \
	docs/u8c_u32alloc.3.gz    \
	docs/u8c_u32cat.3.gz      \
	docs/u8c_u32cmp.3.gz      \
	docs/u8c_u32cp.3.gz       \
	docs/u8c_u32fndchr.3.gz   \
	docs/u8c_u32fndpat.3.gz   \
	docs/u8c_u32free.3.gz     \
	docs/u8c_u32ins.3.gz      \
	docs/u8c_u32substr.3.gz   \
	docs/u8c_u32sz.3.gz       \
	docs/u8c_u32max.3.gz      \
	docs/u8c_ver.3.gz         \
	docs/u8c_vfmt.3.gz        \
	docs/u8c_vprint.3.gz
$(DOCS):
	gzip --keep $(DOCS:.gz=)
test: $(LIB) test.c
	$(CC) -std=c2x -Wall -Wextra -Wpedantic -Iinclude -O3 -g -L. -lu8c -o $@ $@.c
.PHONY: clean docs install runtest
clean:
	rm --force test $(DOCS) $(LIB) $(OBJS)
docs: $(DOCS)
install: $(LIB) $(DOCS)
	mkdir --parents $(DESTDIR)/include/u8c
	mkdir --parents $(DESTDIR)/lib
	mkdir --parents $(DESTDIR)/share/man/man3
	install --mode=444 --verbose $(DOCS) $(DESTDIR)/share/man/man3
	install --mode=444 --verbose $(HDRS) $(DESTDIR)/include/u8c
	install --mode=555 --verbose $(LIB) $(DESTDIR)/lib
runtest: test
	export LD_LIBRARY_PATH=$(CURDIR) && ./$^

.DEFAULT_GOAL = $(LIB)
CC            = gcc
CFLAGS        = -std=c2x -Wall -Wextra -Wmissing-prototypes -pedantic-errors -Iinclude -fPIC
ifeq ($(thrdsafe),1)
CFLAGS += -Du8c_bethrdsafe
endif
ifeq ($(debug),1)
CFLAGS += -O0 -g
else
CFLAGS += -Os -DNDEBUG
endif
LDFLAGS = -shared
ifeq ($(thrdsafe),1)
LDFLAGS += -lpthread
endif
HDRS = \
	include/u8c/SIZE_C.h \
	include/u8c/chk.h    \
	include/u8c/err.h    \
	include/u8c/fmt.h    \
	include/u8c/main.h   \
	include/u8c/str.h    \
	include/u8c/u16.h    \
	include/u8c/u8.h
HDRS_PRIV = \
	include/u8c/intern.h
SRCS = \
	src/u8c/chk.h.d/isalnum.c     \
	src/u8c/chk.h.d/isalpha.c     \
	src/u8c/chk.h.d/iscntrl.c     \
	src/u8c/chk.h.d/isdigit.c     \
	src/u8c/chk.h.d/islower.c     \
	src/u8c/chk.h.d/ispunct.c     \
	src/u8c/chk.h.d/isspace.c     \
	src/u8c/chk.h.d/isspace.c     \
	src/u8c/chk.h.d/issurro.c     \
	src/u8c/chk.h.d/isupper.c     \
	src/u8c/chk.h.d/isxdigit.c    \
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
	src/u8c/main.h.d/abrtfn.c     \
	src/u8c/main.h.d/debug.c      \
	src/u8c/main.h.d/end.c        \
	src/u8c/main.h.d/init.c       \
	src/u8c/main.h.d/thrdsafe.c   \
	src/u8c/main.h.d/uniblk.c     \
	src/u8c/main.h.d/uninm.c      \
	src/u8c/str.h.d/stralloc.c    \
	src/u8c/str.h.d/strcat.c      \
	src/u8c/str.h.d/strcmp.c      \
	src/u8c/str.h.d/strcp.c       \
	src/u8c/str.h.d/strfndchr.c   \
	src/u8c/str.h.d/strfndpat.c   \
	src/u8c/str.h.d/strfree.c     \
	src/u8c/str.h.d/strins.c      \
	src/u8c/str.h.d/strsubstr.c   \
	src/u8c/str.h.d/strsz.c       \
	src/u8c/u8.h.d/u8alloc.c      \
	src/u8c/u8.h.d/u8dec.c        \
	src/u8c/u8.h.d/u8enc.c        \
	src/u8c/u8.h.d/u8free.c       \
	src/u8c/u16.h.d/u16alloc.c    \
	src/u8c/u16.h.d/u16free.c
OBJS = $(SRCS:.c=.o)
LIB  = libu8c.so
$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJS): $(HDRS) $(HDRS_PRIV)
test: $(LIB) test.c
	$(CC) -std=c2x -Wall -Wextra -Wpedantic -Iinclude -O3 -g -L. -lu8c -o $@ $@.c
.PHONY: clean install
clean:
	rm --force test $(LIB) $(OBJS)
install: $(LIB)
	mkdir --parents $(DESTDIR)/include/u8c
	mkdir --parents $(DESTDIR)/lib
	install --mode=444 --verbose $(HDRS) $(DESTDIR)/include/u8c
	install --mode=555 --verbose $(LIB) $(DESTDIR)/lib

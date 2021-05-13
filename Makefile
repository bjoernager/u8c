CC     =  clang
CFLAGS =  -std=c17 -Wall -Wextra -Wpedantic -fPIC -Iinclude -march=native -mtune=native -O3
ifneq ($(debug),1)
CFLAGS += -DNDEBUG
else
CFLAGS += -g
endif
LDFLAGS = -shared
SRCS = \
	src/u8c/free.c \
	src/u8c/print.c \
	src/u8c/u8dec.c \
	src/u8c/u8enc.c
HDRS = \
	include/u8c/fmttyp.h \
	include/u8c/free.h \
	include/u8c/print.h \
	include/u8c/u8dec.h \
	include/u8c/u8enc.h
OBJS = $(SRCS:.c=.o)
LIB  = u8c.so
$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJS): $(HDRS)
.PHONY: clean
clean:
	rm $(OBJS)
.PHONY: purge
purge:
	rm $(LIB) $(OBJS)
.PHONY: install
install: $(LIB)
	mkdir --parents $(DESTDIR)/include/u8c
	mkdir --parents $(DESTDIR)/lib
	install --mode=444 $(HDRS) $(DESTDIR)/include/u8c
	install --mode=555 $(LIB) $(DESTDIR)/lib
.PHONY: uninstall
uninstall:
	rm --force --recursive $(DESTDIR)/include/u8c/
	rm --force --recursive $(DESTDIR)/lib/$(LIB)

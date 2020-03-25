CFLAGS =  -pedantic-errors -ggdb -lm -trigraphs
CC = gcc
BIN = errno
CONFIG = errno.config
BIN_PATH = /usr/local/bin/
CONFIG_PATH = /home/debian/.config/errno/

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
LIBS := $(wildcard *.h)

a.out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(BIN)

.PHONY clean :
clean:
	rm $(OBJS) $(BIN)

install:
	install $(BIN) $(BIN_PATH)
	mkdir $(CONFIG_PATH)
	install $(CONFIG) $(CONFIG_PATH)


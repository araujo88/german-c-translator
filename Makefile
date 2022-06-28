CC=gcc
CFLAGS=-g -Wall

BIN=german-translator

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	$(RM) -rf $(BIN) *.dSYM
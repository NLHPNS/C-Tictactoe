CC = clang
CFLAGS = -Wall -Wvla -Werror -gdwarf-4

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

.PHONY: all
all: Tictactoe

Tictactoe: main.c 
	$(CC) $(CFLAGS) -o Tictactoe main.c tictactoe.c

.PHONY: clean
clean:
	rm -f Tictactoe


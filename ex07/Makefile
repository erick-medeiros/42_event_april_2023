NAME = smallest
CC = gcc
CFLAGS = -w -include stdio.h -include stdlib.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) smallest.c

clean:
	$(RM) $(NAME)

re: clean all

run: all
	wc -c smallest.c
	./$(NAME) 1 2 || true

.PHONY: all clean re run
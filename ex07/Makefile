NAME = smallest

all: $(NAME)

$(NAME): smallest.c
	$(CC) -o $(NAME) smallest.c

clean:
	$(RM) $(NAME)

re: clean all

run: all
	wc -c smallest.c
	./$(NAME) 1 2 || true

.PHONY: all clean re run
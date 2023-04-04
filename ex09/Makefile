NAME = frame

all: $(NAME)

$(NAME): frame.c
	gcc -o $(NAME) $<

clean:
	$(RM) $(NAME)

re: clean all

run: all
	./$(NAME)

.PHONY: all clean re run
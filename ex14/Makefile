NAME = sastantua

all: $(NAME)

$(NAME): main.c
	$(CC) -o $(NAME) $<

fclean:
	$(RM) $(NAME)

re: fclean all

test: all
	bash test.sh

.PHONY: all fclean re test

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c parse.c init.c
OBJ = $(SRC:.c=.o)


NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

d:
	gdbgui ./$(NAME)

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)

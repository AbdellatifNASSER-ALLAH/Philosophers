
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = main.c parse.c init.c utils.c routine.c cleanup.c wrappers.c data_utils.c\
      forks.c print_state.c philo_habits.c monitor.c
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

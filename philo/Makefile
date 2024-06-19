NAME	= philo
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= philo.c ./utils/init_data.c  ./utils/utils.c ./utils/add_philos.c ./utils/actions.c ./utils/ft_sleep.c ./utils/create_threads.c ./utils/checks.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

run: all
	./philo 10 350 200 200

re: fclean all
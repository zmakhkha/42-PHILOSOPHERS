M_NAME = philo_bonus

SRC_MN =	main.c \
			commons/dll/ft_lst_addback.c \
			commons/dll/ft_lst_addfront.c \
			commons/dll/ft_lst_get_end.c \
			commons/dll/ft_lst_new.c \
			commons/dll/ft_lst_utils.c \
			commons/ft_habits.c \
			commons/ft_parsing.c \
			commons/ft_philo.c \
			commons/ft_simulation.c \
			commons/ft_time.c \
			commons/ft_utils1.c \
			commons/ft_utils2.c

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	@$(CC)  $(CFLAGS) $(OBJ) -o $(M_NAME) -g -fsanitize=thread -lpthread

%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@ && clear

clean:
	@rm -f $(OBJ) && clear

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

wq	: re clean

.PHONY: all clean fclean re 
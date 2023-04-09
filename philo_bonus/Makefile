M_NAME = philo_bonus

SRC_MN =	main.c \
			common_files/dll/ft_lst_addback.c \
			common_files/dll/ft_lst_addfront.c \
			common_files/dll/ft_lst_get_end.c \
			common_files/dll/ft_lst_new.c \
			common_files/dll/ft_lst_utils.c \
			common_files/ft_habits.c \
			common_files/ft_parsing.c \
			common_files/ft_philo.c \
			common_files/ft_simulation.c \
			common_files/ft_time.c \
			common_files/ft_utils1.c \
			common_files/ft_utils2.c

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) -o $(M_NAME) 

%.o:%.c common_files/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(M_NAME)

re	: fclean	all

.PHONY: all clean fclean re 
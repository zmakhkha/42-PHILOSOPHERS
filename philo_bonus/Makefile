M_NAME = philo_bonus

SRC_MN =	main.c \
			common_files/dll/ft_lst_new.c \
			common_files/dll/ft_lst_addback.c \
			common_files/dll/ft_lst_get_end.c \
			common_files/dll/ft_lst_addfront.c \
			common_files/dll/ft_lst_utils.c \
			common_files/bonus_utils.c \
			common_files/ft_long_atoi.c \
			common_files/ft_putnbr.c \
			common_files/ft_routine.c \
			common_files/ft_sems.c \
			common_files/ft_time_utils.c \
			common_files/ft_utils.c \
			common_files/parsing_utils.c \
			common_files/ft_actions.c \
			common_files/ft_itoa.c

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
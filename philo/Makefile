M_NAME = philo

SRC_MN =	main.c \
			common_files/ft_utils.c \
			common_files/ft_utils2.c \
			common_files/ft_actions.c \
			common_files/dll/ft_lst_new.c \
			common_files/dll/ft_lst_addback.c \
			common_files/dll/ft_lst_get_end.c \
			common_files/dll/ft_lst_addfront.c \
			common_files/dll/ft_lst_utils.c \
			common_files/ft_initiate.c \
			common_files/ft_habbits.c \
			common_files/ft_long_atoi.c \
			common_files/ft_putnbr.c \
			parsing/parsing_utils01.c \

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	@$(CC)  $(CFLAGS) $(OBJ) -o $(M_NAME) -g -fsanitize=address

%.o:%.c common_files/philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

.PHONY: all clean fclean re 
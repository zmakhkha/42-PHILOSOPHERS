
LIBFT_A_PATH = ../libft/libft.a
M_NAME = philo

SRC_MN =	main.c \
			../parsing/parsing_utils01.c \

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(M_NAME) 

$(M_NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) $(LIBFT_A_PATH) -o $(M_NAME)

%.o:%.c common_files/philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

.PHONY: all clean fclean re 
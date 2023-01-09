NAME	= pipex
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
SRC		= ft_split.c pipex.c process.c utils.c
B_SRC	= ft_split.c process.c utils.c bonus.c

OBJ		= $(SRC:.c=.o)
B_OBJ	= $(B_SRC:.c=.o)

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

bonus:
		$(CC) $(FLAGS) $(B_SRC) -o $(NAME)

clean:
		$(RM) $(OBJ) $(B_OBJ)

fclean:
		$(RM) $(OBJ) $(B_OBJ) $(NAME) $(BONUS)

re:	fclean all

.PHONY: clean fclean re bonus
NAME		=	pipex
NAME_BONUS 	= pipex_bonus
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
SAN			=	-fsanitize=address -O1 -fno-omit-frame-pointer

SRC			= pipex.c errors.c children.c utils.c ft_split.c free.c 

SRC_BONUS 	= pipex_bonus.c errors.c children_bonus.c utils.c ft_split.c free.c 

OBJ			= $(SRC:.c=.o)

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

sanitize:
		$(CC) $(FLAGS) $(SAN) $(SRC) -o $(NAME)

bonus:	
		$(CC) $(FLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
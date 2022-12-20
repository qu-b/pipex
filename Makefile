NAME	=	pipex
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
SAN		=	-fsanitize=address -O1 -fno-omit-frame-pointer

SRC		= pipex.c errors.c child_processes.c utils.c ft_split.c free.c \

OBJ		= $(SRC:.c=.o)

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

sanitize:
		$(CC) $(FLAGS) $(SAN) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
##
## Makefile for  in /home/brice/tech2/PSU_2016_malloc
## 
## Made by vandri_b
## Login   <brice@epitech.net>
## 
## Started on  Thu Feb  2 01:59:05 2017 vandri_b
## Last update Thu Feb  9 15:46:20 2017 Walker
##

SRCS		=	malloc.c

RM		=	rm -f

NAME		=	libmy_malloc.so

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGSLIB	=	-Wall -Werror -Wextra -fPIC -c -o

CFLAGSDYN	=	-shared -o

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(CFLAGSLIB) $(OBJ) $(SRCS) && $(CC) $(CFLAGSDYN) $(NAME) $(OBJ)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.phony		:	all clean fclean re

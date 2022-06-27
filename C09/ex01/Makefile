SRCS	=  ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

HEADERS	=	includes/

OBJS	=	${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = gcc

NAME 	=	libft.a

RM = rm -f

.c.o	:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${HEADERS}

${NAME}	:	${OBJS}
		ar -rc ${NAME} ${OBJS}

all :	${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re :	fclean all

.PHONY : all clean fclean re

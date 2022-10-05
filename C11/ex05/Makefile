SRCS = $(wildcard srcs/*.c)

HEADERS = includes/

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME  = do-op

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${HEADERS}

${NAME} : ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re

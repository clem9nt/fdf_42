.PHONY : all clean fclean re

SRCS = get_next_line.c \
	   get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

OBJS = ${SRCS:.c=.o}
# ${OBJS} : ${SRCS}
# 	${CC} ${CFLAGS} ${SRCS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

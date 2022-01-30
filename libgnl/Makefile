SRCS = get_next_line.c \
	   get_next_line_utils.c

# Compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
OBJS = $(SRCS:.c=.o)
NAME = libgnl.a

# Cleanup
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

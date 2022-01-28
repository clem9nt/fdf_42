YELLOW:=\033[0;33m
END:=\x1b[0m

.PHONY : all clean fclean re

SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/read.c \
	   srcs/hook.c \
	   srcs/hook_events_global.c \
	   srcs/hook_events_modes.c \
	   srcs/render.c \
	   srcs/projection.c \
	   srcs/color.c \
	   srcs/motion.c \
	   srcs/security.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBRAIRIES = -L libmlx -lmlx -L libft -lft -L libgnl -lgnl
FRAMEWORKS = -framework OpenGl -framework Appkit
NAME = fdf
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "${YELLOW}Libft compilation...${END}"
	@make extra -C libft
	@echo "${YELLOW}Libgnl compilation...${END}"
	@make -C libgnl
	@echo "${YELLOW}Libmlx compilation...${END}"
	@make -C libmlx 2>/dev/null
	@echo "${YELLOW}Mandatory part compilation...${END}"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRAIRIES) $(FRAMEWORKS) -o $(NAME)
	@echo "${YELLOW}Done.${END}"

clean :
	@echo "${YELLOW}Remove libft objects...${END}"
	@make clean -C libft
	@echo "${YELLOW}Remove libgnl objects...${END}"
	@make clean -C libgnl
	@echo "${YELLOW}Remove libmlx objects...${END}"
	@make clean -C libmlx
	$(RM) $(OBJS)

fclean : clean
	@echo "${YELLOW}Remove libft...${END}"
	@make fclean -C libft
	@echo "${YELLOW}Remove libgnl...${END}"
	@make fclean -C libgnl
	$(RM) $(NAME)
	@echo "${YELLOW}Done.${END}"

re : fclean all

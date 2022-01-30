# Sources
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

# Compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
LIBRAIRIES = -L libmlx -lmlx -L libft -lft -L libgnl -lgnl
FRAMEWORKS = -framework OpenGl -framework Appkit
NAME = fdf

# Cleanup
RM = rm -f

# Colors
YELLOW:=\033[0;33m
END:=\x1b[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@echo "$(YELLOW)Libft ready.$(END)"
	@make -C libgnl
	@echo "$(YELLOW)Libgnl ready.$(END)"
	@make -C libmlx 2>/dev/null
	@echo "$(YELLOW)Libmlx ready.$(END)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRAIRIES) $(FRAMEWORKS) -o $(NAME)
	@echo "$(YELLOW)Fdf ready.$(END)"

clean :
	@make clean -C libft
	@echo "$(YELLOW)Libft objects removed.$(END)"
	@make clean -C libgnl
	@echo "$(YELLOW)Libgnl objects removed.$(END)"
	@make clean -C libmlx
	@echo "$(YELLOW)Libmlx objects removed.$(END)"
	$(RM) $(OBJS)
	@echo "$(YELLOW)Fdf objects removed.$(END)"

fclean : clean
	@make fclean -C libft
	@echo "$(YELLOW)Libft removed.$(END)"
	@make fclean -C libgnl
	@echo "$(YELLOW)Libgnl removed.$(END)"
	$(RM) $(NAME)
	@echo "$(YELLOW)Fdf removed.$(END)"

re : fclean all

.PHONY : all clean fclean re

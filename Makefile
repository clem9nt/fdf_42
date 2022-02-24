# ========== [ Project files ]

NAME = fdf

LIB_DIR		= lib
LIB			= libft libmlx
LIB			:= $(LIB:%=$(LIB_DIR)/%)

INC_DIR		= include
INC			= $(INC_DIR) \
			  $(LIB:%=%/$(INC_DIR)) $(LIB)

FRAMEWORK	= -framework OpenGl -framework Appkit

SRC_DIR		= src
SRCS		= main.c				\
			  init.c 				\
			  read.c 				\
			  hook.c 				\
			  hook_events_global.c 	\
			  hook_events_modes.c 	\
			  render.c 				\
			  projection.c 			\
			  color.c 				\
			  motion.c 				\
			  security.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

OBJS 		:= $(SRCS:.c=.o)

# ========== [ Compiler flags ]

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Wconversion -Wsign-conversion

CPPFLAGS	+= $(INC:%=-I%)
LDFLAGS 	+= $(LIB:%=-L%) $(FRAMEWORK)
LDLIBS		+= $(LIB:$(LIB_DIR)/lib%=-l%)

# ========== [ Misc ]

RM 		= rm -f
MAKE	= make -C
MUTE	= 1>/dev/null 2>/dev/null

# ========== [ Recipe ]

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) $(LIB_DIR)/libft $(MUTE)
	@$(ECHO)"LIBFT : $(G)ready$(END)"
	@$(MAKE) $(LIB_DIR)/libmlx $(MUTE)
	@$(ECHO)"LIBMLX: $(G)ready$(END)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@$(ECHO)"FDF   : $(G)ready$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"FDF   : $(G)created $(END)$@"

clean:
	@$(MAKE) $(LIB_DIR)/libft clean $(MUTE)
	@$(ECHO)"LIBFT : $(R)objects removed$(END)"
	@$(MAKE) $(LIB_DIR)/libmlx clean $(MUTE)
	@$(ECHO)"LIBMLX: $(R)objects removed$(END)"
	@$(RM) $(OBJS)
	@$(ECHO)"FDF   : $(R)objects removed$(END)"

fclean: clean
	@$(MAKE) $(LIB_DIR)/libft fclean $(MUTE)
	@$(ECHO)"LIBFT : $(R)removed$(END)"
	@$(RM) $(NAME)
	@$(ECHO)"FDF   : $(R)removed$(END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@$(ECHO)"FDF   : $(G)checke$(END) sources"
	@norminette -R CheckDefine $(INC_DIR) | grep -v "OK" || true
	@$(ECHO)"FDF   : $(G)checke$(END) headers"

update:
	@git pull
	@git submodule update
	@$(ECHO)"$(G)updated$(END)\n"

test: all
	./tests/all.sh

re: fclean all

.PHONY: all clean fclean re

# ========== [ Stdout ]

R		= $(shell tput setaf 1)
G		= $(shell tput setaf 2)
Y		= $(shell tput setaf 3)
B		= $(shell tput setaf 4)
M		= $(shell tput setaf 5)
C		= $(shell tput setaf 6)
W		= $(shell tput setaf 7)
K		= $(shell tput setaf 8)
END		= $(shell tput sgr0)
ECHO	= echo -n "\r\033[K"

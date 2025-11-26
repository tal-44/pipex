NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# Source files
SRCS	= src/main.c \
		  src/pipex.c \
		  src/execute.c \
		  src/checks.c \
		  src/utils/utilsa.c \
		  src/utils/utilsb.c \
		  src/utils/ft_split.c \
		  src/utils/ft_printf/ft_printf.c \
		  src/utils/ft_printf/ft_printf_utils.c

# Object files (replaces src/ with obj/ and .c with .o)
OBJS	= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

# Pattern rule: compiles any .c file in src/ to .o file in obj/
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	@$(RM) obj
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re

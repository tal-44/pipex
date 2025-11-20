# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pipex <pipex@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by pipex             #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by pipex            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= pipex

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Directories
SRC_DIR		= src
BONUS_DIR	= bonus
INC_DIR		= includes
OBJ_DIR		= obj
BONUS_OBJ_DIR	= obj_bonus

# Source files
SRC_FILES	= main.c utils.c
BONUS_FILES	= main_bonus.c utils_bonus.c

# Full paths
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS	= $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

# Object files
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS	= $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

# Include flags
INC_FLAGS	= -I$(INC_DIR)

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) bonus compiled successfully!$(RESET)"

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

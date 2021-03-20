# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/03/20 13:28:59 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = 42sh
LIBFT = libft/libft.a
LIBFT_OPT = "LIBFT_EXIT_ON_ALLOC_FAIL=1"

# compilation variables
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
CC = gcc

# 42sh																		   #
INCLUDES = -I. -Iincludes -Ilibft
42sh_INC = includes/forty_two_sh.h includes/typedefs.h src/errors/errors.h 
42sh = main.o 

42sh_OBJS = $(addprefix $(OBJS_DIR)/, ${42sh})

# objects directory
OBJS_DIR = objs

# Colors
BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[93m
BLUE	= \033[34m
MAGENTA	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
RESET	= \033[0m

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #
all: $(NAME)

$(NAME): $(42sh_OBJS) $(LIBFT)
	@$(CC) -o $(NAME) $(42sh_OBJS) $(LIBFT)
	@echo "$(GREEN)program$(RESET) $(NAME): $(GREEN)UPDATED!$(RESET)";

$(LIBFT): force
	@env $(LIBFT_OPT) make -C libft/

force:

$(42sh_OBJS): $(OBJS_DIR)/%.o : src/%.c $(42sh_INC) | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I src/
	@echo "$(YELLOW)OBJ$(RESET) $<: $(YELLOW)UPDATED!$(RESET)";

$(OBJS_DIR):
	@if [ ! -d $(OBJS_DIR) ]; then \
		echo "$(CYAN)DIR$(RESET) $(OBJS_DIR)/: $(CYAN)CREATED!$(RESET)"; \
		mkdir $(OBJS_DIR); \
	fi;

clean:
	@make clean -C libft/
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(RED)OBJ$(RESET) 42sh objs: $(RED)REMOVED!$(RESET)"; \
		rm -rf $(OBJS_DIR); \
	fi;

fclean: clean
	@make fclean -C libft/
	@if [ -f $(NAME) ]; then \
		echo "$(RED)program$(RESET) $(NAME): $(RED)REMOVED!$(RESET)"; \
		rm -f $(NAME); \
	fi;

re:
	@make fclean
	@make all

.PHONY: all clean fclean re libft force

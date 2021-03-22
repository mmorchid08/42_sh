# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/03/22 11:00:59 by ylagtab          ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
CC = gcc

# 42sh																		   #
INCLUDES =	-Iincludes

42sh_INC =	includes/forty_two_sh.h includes/typedefs.h includes/constants.h \
			src/errors/errors.h src/parser/parser.h src/parser/internals.h \
			src/parser/lexer/lexer.h src/parser/lexer/internals.h

42sh = 	delete_functions.o main.o \
		\
		errors/errors.o \
		\
		parser/lexer/lexer.o parser/lexer/lexer_advance.o \
		parser/lexer/lexer_handle_io_number.o parser/lexer/string.o \
		parser/lexer/lexer_handle_operator.o parser/lexer/lexer_handle_word.o \
		parser/lexer/lexer_print_tokens.o parser/lexer/lexer_push_token.o \
		parser/lexer/lexer_skip_whitespaces.o parser/lexer/util.o \
		parser/lexer/lexer_operator_len.o \
		parser/parser.o

42sh_OBJS = $(addprefix $(OBJS_DIR)/, ${42sh})

# objects directory
OBJS_DIR = objs

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(42sh_OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(42sh_OBJS) $(LIBFT)

$(LIBFT): force
	@env $(LIBFT_OPT) make -C libft/

force:
$(OBJS_DIR)/%.o : src/%.c $(42sh_INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MACROS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re libft force

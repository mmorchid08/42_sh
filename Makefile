# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/03/30 15:59:32 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = 42sh
LIBFT = libft/libft.a
PARSER = src/parser/parser.a
JOBS = src/execution/job_control/job_control.a
LIBFT_OPT = "LIBFT_EXIT_ON_ALLOC_FAIL=1"

# compilation variables
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
CC = gcc
PARSER_ENV=42sh_headers=$(mkfile_dir)/includes/forty_two_sh.h 42sh_include_dirs=-I$(mkfile_dir)includes/

# 42sh																		   #
INCLUDES =	-Iincludes

42sh_INC =	includes/forty_two_sh.h includes/typedefs.h includes/constants.h \
			src/errors/errors.h

42sh = 	delete_functions.o main.o errors/errors.o \
	execution/exec_tools.o \
	execution/execute_commands.o \
	execution/execute_logic_seq.o \
	execution/execute_pipe_seq.o \
	execution/execute_simple_cmd.o \
	execution/get_exit_code.o \
	execution/remove_quotes.o \
	execution/wait_children.o \
	execution/job_control/execute_job.o \
	execution/job_control/get_job_by_selector.o \
	execution/job_control/get_latest_jobs.o \
	execution/job_control/job_builtins.o \
	execution/job_control/job_list.o \
	execution/job_control/new_job.o \
	execution/job_control/notify_jobs.o \
	execution/job_control/print_job.o \
	execution/job_control/process.o \
	execution/job_control/update_job.o \
	execution/job_control/update_stopped_jobs.o \
	execution/job_control/wait_job.o
	

42sh_OBJS = $(addprefix $(OBJS_DIR)/, ${42sh})

# objects directory
OBJS_DIR = objs

#
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(42sh_OBJS) $(LIBFT) $(PARSER)
	$(CC) -o $(NAME) $(42sh_OBJS) $(LIBFT) $(PARSER)

$(LIBFT): force
	@env $(LIBFT_OPT) make -C libft/

$(PARSER): force
	@env $(PARSER_ENV) make -C src/parser/

force:

$(OBJS_DIR)/%.o : src/%.c $(42sh_INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C libft/
	make fclean -C src/parser/
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re libft force

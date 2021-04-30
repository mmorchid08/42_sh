# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/28 10:25:34 by mel-idri          #+#    #+#              #
#    Updated: 2021/04/30 16:45:56 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = readline.a
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG), true)
	CFLAGS = -g -Wall -Wextra
endif
CC = gcc
SRCS = add_hist_entry.c \
	append_to_last_hist_entry.c \
	check_used_capabilities.c \
	clone_dynstr_vector.c \
	delete_next_char.c \
	delete_prev_char.c \
	dynstr_vec_to_str.c \
	dynstr_vector_equ.c \
	exit_error.c \
	free_dyn_str.c \
	free_history_allocs.c \
	get_last_hist_entry.c \
	goto_end.c \
	goto_home.c \
	goto_next_char.c \
	goto_next_line.c \
	goto_next_word.c \
	goto_previous_char.c \
	goto_previous_line.c \
	goto_previous_word.c \
	handle_control_chars.c \
	handle_termcap_sequences.c \
	init_history_state.c \
	init_readline_state.c \
	kill_cursor_to_end.c \
	mark_hist_entry_as_dirty.c \
	merge_lines.c \
	move_cursor_to.c \
	print_current_hist_entry.c \
	print_newline.c \
	readline.c \
	reprint_char.c \
	reprint_line.c \
	show_next_hist_entry.c \
	show_previous_hist_entry.c \
	signals.c \
	str_to_dynstr_vec.c \
	submit_command.c \
	update_lines.c \
	update_win_dimensions.c \
	wrap_cursor.c \
	write_char.c \
	yank_clipboard.c

OBJS = $(addprefix  objs/, $(SRCS:.c=.o))
INCLUDES = readline.h readline_typedefs.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

objs/%.o : %.c | objs
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJS) : $(INCLUDES)

objs:
	mkdir objs

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

force:

.PHONY: all fclean re clean force

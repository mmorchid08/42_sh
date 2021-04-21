/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:02:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/21 09:42:49 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

static void	remove_ending_backslash(char **cmd_line)
{
	size_t	cmd_len;

	cmd_len = ft_strlen(*cmd_line);
	if ((*cmd_line)[cmd_len - 1] == BACK_SLASH)
	{
		(*cmd_line)[cmd_len - 1] = '\0';
		return ;
	}
}

t_vector	*read_commands(void)
{
	char			*line;
	char			*cmd_line;
	t_readline_ret	read_ret;
	t_lexer_ret		*lex_ret;
	char			*prompt;
	t_bool			first_read;
	t_vector		*commands;

	cmd_line = ft_strdup("");
	prompt = prompt_1();
	first_read = TRUE;
	while (1)
	{
		read_ret = readline_21sh(&line, prompt);
		if ((read_ret == EXIT && first_read) || read_ret == ERROR)
			exit(read_ret);
		if (read_ret == EXIT)
			break ;
		if (read_ret == INTERRUPTED)
			return (NULL);
		cmd_line = ft_strjoin_free(cmd_line, line, 1, 1);
		lex_ret = lexer(cmd_line, TRUE);
		if (lex_ret->is_matched == TRUE)
			break ;
		if (lex_ret->unmached_char == BACK_SLASH)
			remove_ending_backslash(&cmd_line);
		else
			cmd_line = ft_strjoin_free(cmd_line, "\n", 1, 0);
		ft_strdel(&prompt);
		prompt = "> ";
		first_read = FALSE;
	}
	lexer_add_newline_token(lex_ret->tokens);
	lexer_print_tokens(lex_ret->tokens);
	commands = parse_complete_commands(lex_ret->tokens);
	vector_free(lex_ret->tokens);
	print_commands(commands);
	ft_strdel(&cmd_line);
	ft_strdel(&prompt);
	ft_memdel((void **)&lex_ret);
	return (commands);
}

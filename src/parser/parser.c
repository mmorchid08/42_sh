/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:28:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/19 15:08:10 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	print_unmatch_error(t_lexer_ret *lex_ret)
{
	ft_printf(2, "42h: unexpected EOF while looking for matching `%c\"\n",
		lex_ret->unmached_char);
}

t_vector	*parser(char *line)
{
	t_lexer_ret	*lex_ret;
	t_vector	*commands;

	(void)line;
	lex_ret = lexer(line, FALSE);
	if (lex_ret->is_matched == FALSE)
	{
		print_unmatch_error(lex_ret);
		vector_free(lex_ret->tokens);
		return (NULL);
	}
	lexer_add_newline_token(lex_ret->tokens);
	lexer_print_tokens(lex_ret->tokens);
	commands = parse_complete_commands(lex_ret->tokens);
	print_commands(commands);
	return (commands);
}

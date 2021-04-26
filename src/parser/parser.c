/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:28:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/24 15:17:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_vector	*parser(char *line)
{
	t_lexer_ret	*lex_ret;
	t_vector	*commands;

	lex_ret = lexer(line);
	if (lex_ret->is_matched == FALSE && lex_ret->unmatched_char != BACK_SLASH)
	{
		unmatch_quote_error(lex_ret->unmatched_char);
		vector_free(lex_ret->tokens);
		return (NULL);
	}
	lexer_add_newline_token(lex_ret->tokens);
	commands = parse_complete_commands(lex_ret->tokens);
	vector_free(lex_ret->tokens);
	free(lex_ret);
	return (commands);
}

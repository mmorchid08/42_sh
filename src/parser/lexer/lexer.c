/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:01:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 09:34:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_lexer		*lexer_init(char *line)
{
	t_lexer	*lex;

	lex = (t_lexer*)ft_malloc(sizeof(t_lexer));
	lex->tokens_list = vector_init(sizeof(t_token), del_token);
	lex->word = string_new();
	lex->line = line;
	lex->i = 0;
	lex->c = lex->line[lex->i];
	lex->quote = 0;
	lex->backslash = FALSE;
	return (lex);
}

t_vector	*lexer(char *line)
{
	t_lexer	*lex;

	lex = lexer_init(line);
	while (lex->c)
	{
		if (ft_isdigit(lex->c))
			lexer_handle_io_number(lex);
		if (lexer_is_word(lex->c, 0))
			lexer_handle_word(lex);
		if (lex->word->length > 0)
			lexer_push_token(lex, WORD);
		if (lexer_is_operator(lex->c, 0))
			lexer_handle_operator(lex);
		lexer_skip_whitespaces(lex);
	}
	return (lex->tokens_list);
}

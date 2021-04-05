/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:01:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/05 18:21:28 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_lexer	*lexer_init(char *line)
{
	t_lexer	*lex;

	lex = (t_lexer*)ft_malloc(sizeof(t_lexer));
	lex->tokens_list = vector_init(sizeof(t_token), del_token);
	lex->word = string_new();
	lex->line = line;
	lex->i = 0;
	lex->c = lex->line[lex->i];
	return (lex);
}

static void		lexer_clean(t_lexer **lex)
{
	string_free((*lex)->word);
	ft_bzero(*lex, sizeof(t_lexer));
	ft_memdel((void**)lex);
}

int				lexer(t_vector **tokens, char *line)
{
	static t_lexer	*lex;

	lex = lexer_init(line);
	while (lex->c)
	{
		if (ft_isdigit(lex->c))
			lexer_handle_io_number(lex);
		if (lexer_is_word(lex->c))
			lexer_handle_word(lex);
		if (lex->word->length > 0)
			lexer_push_token(lex, WORD);
		if (lexer_is_operator(lex->c))
			lexer_handle_operator(lex);
		lexer_skip_whitespaces(lex);
	}
	*tokens = lex->tokens_list;
	lexer_clean(&lex);
	return (0);
}

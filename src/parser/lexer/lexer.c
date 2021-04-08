/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:01:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/08 09:50:51 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_lexer	*lexer_init(char *line, t_lexer *old_lex)
{
	t_lexer	*lex;

	lex = (t_lexer *)ft_malloc(sizeof(t_lexer));
	lex->tokens = vector_init(sizeof(t_token), del_token);
	lex->word = string_new();
	lex->line = line;
	lex->i = 0;
	lex->c = lex->line[lex->i];
	lex->quotes_stack = stack_new(sizeof(char), NULL);
	lex->backslash = FALSE;
	return (lex);
}

void	lexer_clean(t_lexer **lex)
{
	string_free((*lex)->word);
	ft_bzero(*lex, sizeof(t_lexer));
	ft_memdel((void **)lex);
}

t_lexer	*lexer(char *line, t_lexer *old_lex)
{
	t_lexer	*lex;

	lex = lexer_init(line, old_lex);
	while (lex->c)
	{
		if (lex->is_word_complete == FALSE)
			lexer_handle_word(lex);
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
	return (lex);
}

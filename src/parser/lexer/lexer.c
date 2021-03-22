/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:01:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 19:34:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_lexer		*lexer_init(char *line, t_bool enable_alias_subtitution)
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
	lex->enable_alias_subtitution = enable_alias_subtitution;
	return (lex);
}

static void	lexer_clean(t_lexer **lex)
{
	string_free((*lex)->word);
	ft_bzero(*lex, sizeof(t_lexer));
	ft_memdel((void**)lex);
}

t_vector	*lexer(char *line, t_bool enable_alias_subtitution)
{
	t_lexer		*lex;
	t_vector	*tokens;

	lex = lexer_init(line, enable_alias_subtitution);
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
	tokens = lex->tokens_list;
	lexer_clean(&lex);
	return (tokens);
}

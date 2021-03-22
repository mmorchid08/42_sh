/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handle_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:00:44 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 10:57:15 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	update_quoting(t_lexer *lex)
{
	if (lex->quote == SINGLE_QUOTE && lex->c == SINGLE_QUOTE)
		lex->quote = 0;
	else if (lex->quote == DOUBLE_QUOTE && lex->c == DOUBLE_QUOTE)
	{
		if (lex->backslash == FALSE)
			lex->quote = 0;
	}
	else if (lex->quote == 0 && lex->backslash == FALSE)
		lex->quote = lexer_quote_type(lex->c);
	if (lex->backslash)
		lex->backslash = FALSE;
	else
		lex->backslash = lex->c == BACK_SLASH && lex->quote != SINGLE_QUOTE;
}

void		lexer_handle_word(t_lexer *lex)
{
	while (lex->c && lexer_is_word(lex->c, lex->quote | lex->backslash))
	{
		update_quoting(lex);
		string_push(lex->word, lex->c);
		lexer_advance(lex, 1);
	}
	lexer_push_token(lex, WORD);
}

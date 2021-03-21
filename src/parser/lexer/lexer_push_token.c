/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_push_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:01:45 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/21 19:01:55 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_push_token(t_lexer *lex, t_token_type token_type)
{
	t_token token;

	if (token_type == WORD || token_type == IO_NUMBER)
		token.data = string_get_data(lex->word);
	else
		token.data = NULL;
	token.type = token_type;
	lex->word->length = 0;
	vector_push(lex->tokens_list, &token);
}

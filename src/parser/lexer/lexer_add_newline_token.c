/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_newline_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:31:37 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/23 16:52:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_add_newline_token(t_vector *tokens)
{
	t_token last_token;

	last_token = ((t_token*)tokens->array)[tokens->length - 1];
	if (last_token.type != SEMI && last_token.type != AMPERSAND)
	{
		last_token.type = NEWLINE;
		vector_push(tokens, &last_token);
	}
}

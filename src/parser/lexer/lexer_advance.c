/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_advance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:02:29 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/21 19:02:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	lexer_advance(t_lexer *lex, size_t by)
{
	lex->i += by;
	lex->c = lex->line[lex->i];
}

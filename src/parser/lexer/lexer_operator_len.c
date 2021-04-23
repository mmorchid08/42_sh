/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_operator_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:59:51 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 11:01:51 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

int		lexer_operator_len(t_token_type type)
{
	if (type == ANDDGREAT || type == GREATANDDASH || type == LESSANDDASH)
		return (3);
	if (type == SEMI || type == AMPERSAND || type == PIPE)
		return (1);
	if (type == GREAT || type == LESS)
		return (1);
	return (2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:36:50 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/27 12:37:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	unexpected_token(t_token_type type)
{
	char *suffix;

	suffix = g_tokens_to_string[type];
	ft_strerror(ESYNTAX, NULL, suffix, FALSE);
}

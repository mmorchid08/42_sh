/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_advance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:48 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 10:22:28 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	simple_advance(t_simple *sim)
{
	++(sim->tokens_index);
	sim->current_token = sim->tokens[sim->tokens_index];
}

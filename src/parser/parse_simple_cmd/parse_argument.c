/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:55:25 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 16:13:46 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	parse_argument(t_parse_simple *sim)
{
	char *arg;

	arg = (char*)sim->current_token.data;
	vector_push(sim->cmd->args, &arg);
	sim->is_done_assigning = TRUE;
}

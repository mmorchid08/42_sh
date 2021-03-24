/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assignment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 16:54:59 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	parse_assignment(t_simple *sim)
{
	t_var *assign;

	assign = (t_var*)sim->current_token.data;
	vector_push(sim->cmd->assignments, assign);
	free(assign);
}

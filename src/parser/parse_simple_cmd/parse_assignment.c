/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assignment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/28 16:57:26 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

void	parse_assignment(t_parse_simple *sim)
{
	t_var *assign;

	assign = (t_var*)sim->current_token.data;
	vector_push(sim->cmd->assignments, assign);
	free(assign);
}

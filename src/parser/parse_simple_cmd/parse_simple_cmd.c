/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:02:06 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 17:14:34 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_simple	*simple_init(t_vector *tokens_vec)
{
	t_simple *sim;

	sim = (t_simple*)ft_malloc(sizeof(t_simple));
	sim->cmd = (t_simple_command*)ft_malloc(sizeof(t_simple_command));
	sim->cmd->args = vector_init(sizeof(char*), free);
	sim->cmd->redirections = vector_init(sizeof(t_redirection), del_redirection);
	sim->cmd->assignments = vector_init(sizeof(t_var), del_var);
	sim->tokens = (t_token*)tokens_vec->array;
	sim->tokens_len = tokens_vec->length;
	sim->tokens_index = 0;
	sim->current_token = sim->tokens[sim->tokens_index];
	return (sim);
}

void			simple_free_all(t_simple *sim)
{
	vector_free(sim->cmd->args);
	vector_free(sim->cmd->redirections);
	vector_free(sim->cmd->assignments);
	free(sim->cmd);
	ft_bzero(sim, sizeof(t_simple));
	free(sim);
}

t_simple_command	*parse_simple_cmd(t_vector *tokens_vec)
{
	t_simple			*sim;
	t_simple_command	*simple_cmd;

	sim = simple_init(tokens_vec);
	while (sim->tokens_index < sim->tokens_len)
	{
		if (lexer_is_redirection(sim->current_token.type))
		{
			if (parse_redirection(sim) == EXIT_FAILURE)
			{
				simple_free_all(sim);
				return (NULL);
			}
		}
		else if (sim->current_token.type == ASSIGNMENT)
			parse_assignment(sim);
		else
			parse_argument(sim);
		simple_advance(sim);
	}
	simple_cmd = sim->cmd;
	free(sim);
	return (simple_cmd);
}

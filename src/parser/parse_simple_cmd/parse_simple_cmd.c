/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:02:06 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 15:31:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_simple	*simple_init(t_vector *tokens_vec)
{
	t_parse_simple *s;

	s = (t_parse_simple*)ft_malloc(sizeof(t_parse_simple));
	s->cmd = (t_simple_command*)ft_malloc(sizeof(t_simple_command));
	s->cmd->args = vector_init(sizeof(char*), free);
	s->cmd->redirections = vector_init(sizeof(t_redirection), del_redirection);
	s->cmd->assignments = vector_init(sizeof(t_var), del_var);
	s->tokens = (t_token*)tokens_vec->array;
	s->tokens_len = tokens_vec->length;
	s->tokens_index = 0;
	s->current_token = s->tokens[s->tokens_index];
	s->is_done_assigning = FALSE;
	return (s);
}

void					simple_free_all(t_parse_simple *sim)
{
	vector_free(sim->cmd->args);
	vector_free(sim->cmd->redirections);
	vector_free(sim->cmd->assignments);
	free(sim->cmd);
	ft_bzero(sim, sizeof(t_parse_simple));
	free(sim);
}

t_simple_command		*parse_simple_cmd(t_vector *tokens_vec)
{
	t_parse_simple		*sim;
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
		else
			parse_word(sim);
		simple_advance(sim);
	}
	simple_cmd = sim->cmd;
	free(sim);
	return (simple_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:37:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 18:55:40 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"

typedef struct	s_simple
{
	t_simple_command	*cmd;
	t_token				*tokens;
	t_token				current_token;
	size_t				tokens_len;
	size_t				tokens_index;
}				t_simple;

void	simple_advance(t_simple *sim);
int		parse_redirection(t_simple *sim);
void	parse_assignment(t_simple *sim);
void	parse_argument(t_simple *sim);

#endif

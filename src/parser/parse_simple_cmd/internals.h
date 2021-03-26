/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:37:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 15:32:54 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "../internals.h"

typedef struct	s_simple
{
	t_simple_command	*cmd;
	t_token				*tokens;
	t_token				current_token;
	size_t				tokens_len;
	size_t				tokens_index;
}				t_simple;

typedef	struct	s_delimiter
{
	char	*str;
	t_bool	is_quoted;
}				t_delimiter;

void	simple_advance(t_simple *sim);
int		parse_redirection(t_simple *sim);
void	parse_assignment(t_simple *sim);
void	parse_argument(t_simple *sim);
int		parse_here_doc(char *delimter_str);

#endif

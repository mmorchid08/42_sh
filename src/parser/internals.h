/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:39:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/27 12:37:29 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "forty_two_sh.h"
# include "lexer/lexer.h"
# include "parse_simple_cmd/parse_simple_cmd.h"
# include "parse_pipe/parse_pipe.h"
# include "parse_and_or/parse_and_or.h"
# include "parse_complete_commands/parse_complete_commands.h"

void	unexpected_token(t_token_type type);

#endif

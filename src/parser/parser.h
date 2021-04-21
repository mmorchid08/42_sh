/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:37:49 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/21 09:32:28 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer/lexer.h"
# include "parse_complete_commands/parse_complete_commands.h"

t_vector	*parser(char *line);
char		*get_job_name(t_vector *tokens_vec);
void		print_commands(t_vector *commands_vec);

#endif

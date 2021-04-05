/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/04 12:01:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include "../libft/libft.h"
# include "constants.h"
# include "typedefs.h"
# include "../src/errors/errors.h"
# include "../src/parser/parser.h"
# include "../src/builtins/env/env.h"
# include <stdbool.h>

/*
**		Builtins
*/

int		jhin(char **cmd);
int		check_is_not(int ret, int is_not);
int		ft_test(char **cmd);
int		ft_echo(char **cmd);

/*
**		free functions
*/

void	del_token(void *element);
void	del_redirection(void *element);
void	del_var(void *element);

/*
** Utils
*/

t_bool	is_quote(char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:45:08 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/01 09:46:36 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	do_tests(int i, int is_not, char **cmd)
{
	if (i == 1)
		return (check_is_not(1, is_not));
	else if (i == 2 && cmd[0])
		return (check_is_not(0, is_not));
	else if (i == 3)
		return (check_is_not(do_tree(cmd[0], cmd[1]), is_not));
	else if (i == 4)
		return (check_is_not(jhin(cmd), is_not));
	else if (i > 4)
	{
		ft_printf(2, "test: too many arguments\n");
		return (2);
	}
	return (0);
}

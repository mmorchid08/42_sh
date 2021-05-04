/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:11:40 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/20 16:19:36 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dyn_str_internal.h"

size_t	get_close_power_of_2(size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		n >>= 1;
		i++;
	}
	return (1 << i);
}

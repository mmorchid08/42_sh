/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:49:44 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:53:20 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10;
		res += *s - '0';
		s++;
	}
	res *= sign;
	if (sign == 1 && res < 0)
		return (-1);
	if (sign == -1 && res > 0)
		return (0);
	return (res);
}

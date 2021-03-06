/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:30:03 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:18:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
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

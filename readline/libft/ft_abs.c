/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:31:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/05/04 13:54:14 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_abs(int n)
{
	long	m;

	m = n;
	if (m < 0)
		return ((unsigned int)(-m));
	return ((unsigned int)m);
}

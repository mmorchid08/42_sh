/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:47:09 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/23 17:36:32 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putnchar(char c, int n)
{
	int ret;

	ret = 0;
	while (n-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

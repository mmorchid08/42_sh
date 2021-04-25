/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 21:56:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/05 16:26:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_pushback_str(t_list **alst, char *str)
{
	t_list	*node;

	node = ft_lstnew(str, ft_strlen(str) + 1);
	if (!node)
		return (-1);
	if (ft_lst_pushback(alst, node) == -1)
		return (-1);
	return (0);
}

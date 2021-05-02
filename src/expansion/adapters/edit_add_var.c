/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_add_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:27:30 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 15:28:30 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	edit_add_var(char *key, char *value, int a, int b)
{
	(void)a;
	(void)b;
	env_set_value(key, value);
}

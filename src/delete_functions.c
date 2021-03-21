/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:08:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/20 17:12:13 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	del_token(void *element)
{
	t_token *token;

	token = (t_token*)element;
	if (token->type == WORD || token->type == IO_NUMBER)
		free(token->data);
	free(token);
}

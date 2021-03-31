/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:08:53 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/24 16:47:49 by ylagtab          ###   ########.fr       */
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

void	del_redirection(void *element)
{
	t_redirection *redirect;

	redirect = (t_redirection*)element;
	free(redirect->righ_fd);
	free(redirect);
}

void	del_var(void *element)
{
	t_var *var;

	var = (t_var*)element;
	free(var->key);
	free(var->value);
	free(var);
}

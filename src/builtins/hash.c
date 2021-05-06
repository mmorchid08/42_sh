/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:55:21 by hmzah             #+#    #+#             */
/*   Updated: 2021/05/06 13:48:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	free_hash_node(void *element)
{
	t_hash_node	*node;

	node = (t_hash_node *)element;
	free(node->key);
	free(node->value);
}

void	hash_init(void)
{
	g_hash = vector_init(sizeof(t_hash_node), free_hash_node);
}

void	insert_name(t_vector *hashtable, char *key, char *value)
{
	t_hash_node	hashnode;

	hashnode.key = ft_strdup(key);
	hashnode.value = ft_strdup(value);
	hashnode.count = 1;
	vector_push(hashtable, &hashnode);
}

void	print_hash(t_vector *hashtable)
{
	t_hash_node	*hashnodes;
	size_t		i;

	if (hashtable == NULL)
		return ;
	if (hashtable->length == 0)
	{
		ft_printf(1, "hash: hash table empty\n");
		return ;
	}
	i = 0;
	hashnodes = hashtable->array;
	ft_printf(1, "hits    command\n");
	while (i < hashtable->length)
	{
		ft_printf(1, "%d    %s\n", hashnodes[i].count, hashnodes[i].value);
		++i;
	}
}

char	*find_key_in_hash(t_vector *hashtable, char *key)
{
	t_hash_node	*hashnodes;
	size_t		i;

	if (hashtable == NULL)
		return (NULL);
	i = 0;
	hashnodes = hashtable->array;
	while (i < hashtable->length)
	{
		if (ft_strequ(hashnodes[i].key, key))
		{
			hashnodes[i].count++;
			return (hashnodes[i].value);
		}
		++i;
	}
	return (NULL);
}

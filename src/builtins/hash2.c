/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:55:25 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/30 14:26:36 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void free_hash_content(t_hash_content **table, unsigned int size,
		void (*del)(void **))
{
    unsigned int i;
    t_hash_content *tmp;
    t_hash_content *to_free;

    i = 0;
    while (++i < size)
        if (table[0][i].key)
        {
            tmp = table[0][i - 1].next;
            while (tmp)
            {
                if(del)
                {
                    del(tmp->value);
                    free(tmp->key);
                }
                to_free = tmp;
                tmp = tmp->next;
                free(to_free);
            }
            del(table[0][i - 1].value);
            free(table[0][i - 1].key);    
        }
    ft_memdel((void **)table);
}

void	print_hash(t_hash_table *hash_tab)
{
    unsigned int i;
    i = 0;
	t_hash_content	*table;
	t_hash_content	*ptr;
	
	table = hash_tab->table;
    while (++i < hash_tab->size)
    {
        if (table[i].key)
        {
            ft_printf(1, "%s	%s\n", table->key, (char *)table->value);
            ptr = table->next;
            while (ptr)
            {
                ft_printf(1, "%s	%s\n", ptr->key, (char *)ptr->value);
                ptr = ptr->next;
            }   
        }
    }
}

void free_hash_table(t_hash_table **hash_tab, void (*del)(void **))
{
    if (hash_tab && *hash_tab)
    {
        free_hash_content(&(*hash_tab)->table, (*hash_tab)->size, del);
        free(*hash_tab);
        *hash_tab = NULL;
    }
}

t_hash_table *new_hash_table(unsigned int size, unsigned int expnading_size)
{
    t_hash_table *table;

    table = ft_memalloc(sizeof(t_hash_table) * size);
    if (table)
    {
        table->size = size;
        table->expanding_size = expnading_size;
        if ((table->table = ft_memalloc(sizeof(t_hash_content) * size)))
            return (table);
        free(table);
    }
    return (NULL);
}

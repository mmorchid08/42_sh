/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:55:21 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/30 14:28:28 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

unsigned long hash_key(const char *key)
{
    unsigned long hash = 0;

    while (*key)
    {
        hash += (unsigned long)*key;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        key++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return (hash);
}

t_hash_table *resize_hashtable(t_hash_table *hash_tab)
{
    unsigned int i;
    t_hash_content *tmp;
    t_hash_table *newtab;
    unsigned int size;

    size = hash_tab->size + hash_tab->expanding_size;
    i = 0;
    newtab = new_hash_table(size, hash_tab->expanding_size);
    while (i < size)
    {
        if (hash_tab->table[i].key)
        {
            hash_insert(newtab, hash_tab->table[i].key,
					hash_tab->table[i].value, 0);
            if ((tmp = hash_tab->table[i].next))
                while (tmp)
                {
                    hash_insert(newtab, tmp->key, tmp->value, 0);
                    tmp = tmp->next;
                }
        }
        i++;
    }
    free_hash_table(&hash_tab, NULL);
    return (newtab);
}

int hash_insert(t_hash_table *hash_tab, char *key, void *value, int expand)
{
    unsigned int pos;
    t_hash_content *tmp;

    if (hash_tab->used_size == hash_tab->size)
        if (!expand || !(hash_tab = resize_hashtable(hash_tab)))
            return (0);
    pos = hash_key(key) % hash_tab->size;
    if (hash_tab->table[pos].key)
    {
        tmp = ft_memalloc(sizeof(t_hash_content));
        tmp->key = key;
        tmp->value = value;
        if (hash_tab->table[pos].last)
            hash_tab->table[pos].last->next = tmp;
        hash_tab->table[pos].last = tmp;
        if (!hash_tab->table[pos].next)
            hash_tab->table[pos].next = tmp;
        hash_tab->used_size++;
        return (1);
    }
    hash_tab->table[pos].key = key;
    hash_tab->table[pos].value = value;
    hash_tab->used_size++;
    return (1);
}

void *hash_find(t_hash_table *hash_tab, const char *key)
{
    unsigned int pos;
    t_hash_content *tmp;

    pos = hash_key(key) % hash_tab->size;
    if (!hash_tab->table[pos].next || ft_strequ(key, hash_tab->table[pos].key))
        return (hash_tab->table[pos].value);
    tmp = hash_tab->table[pos].next;
    while (tmp)
    {
        if (ft_strequ(key, tmp->key))
            return (tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}

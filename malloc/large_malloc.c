/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:50:39 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:50:40 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "malloc.h"

static void		*set_large_block(t_header *header, size_t size)
{
	t_block		*block;

	header->next = NULL;
	header->size = size;
	header->end = (void *)header + header->size - 1;
	header->format = size;
	block = (void *)header + sizeof(t_header);
	block->prev = 0;
	block->next = header->size - sizeof(t_header) - 1;
	block->flag = USED;
	header->first = block;
	return (block);
}

void			free_large(t_header *header, t_block *block)
{
	while (header)
	{
		if (block && block != header->first)
			header = header->next;
		else
		{
			clear_map(header);
			return ;
		}
	}
	return ;
}

void			*large_alloc(size_t size, void **map)
{
	t_header	*tmp;
	t_header	*header;

	size += sizeof(t_header);
	size += (getpagesize() - (size % getpagesize()));
	tmp = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (tmp == MAP_FAILED)
		return (NULL);
	g_map.max_size -= size;
	if (*map == NULL)
	{
		*map = (void *)tmp;
		tmp->prev = NULL;
	}
	else
	{
		header = (t_header *)*map;
		while (header->next)
			header = header->next;
		header->next = tmp;
		tmp->prev = header;
	}
	return (set_large_block(tmp, size));
}

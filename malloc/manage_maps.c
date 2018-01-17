/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:51:27 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:28 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mach/mach_vm.h>
#include <mach/mach_init.h>
#include "malloc.h"
#include "libft.h"

static t_block	*set_first_block(t_header *header, size_t size)
{
	t_block		*first;

	first = (void *)header + sizeof(t_header);
	first->next = size - sizeof(t_header) - 1;
	first->prev = 0;
	first->flag = FREE;
	return (first);
}

t_header		*new_header(void **map, size_t size, t_header *prev, int bsize)
{
	t_header	*header;

	header = (t_header *)*map;
	header->prev = prev;
	header->next = NULL;
	header->end = (void *)header + size - 1;
	header->size = size;
	header->format = bsize;
	header->first = set_first_block(header, size);
	return (header);
}

void			clear_map(t_header *header)
{
	if (header->prev)
		header->prev->next = header->next;
	else
	{
		if (header == (t_header *)g_map.tiny)
			g_map.tiny = (void *)header->next;
		if (header == (t_header *)g_map.small)
			g_map.small = (void *)header->next;
		if (header == (t_header *)g_map.large)
			g_map.large = (void *)header->next;
	}
	if (header->next)
		header->next->prev = header->prev;
	ft_bzero((void *)header, header->size);
	munmap((void *)header, header->size);
}

int				new_map(int bsize, void **map, t_header *prev)
{
	t_header	*header;
	size_t		size;

	size = (bsize + sizeof(t_block)) * 100 + sizeof(t_header);
	size = size + (getpagesize() - (size % getpagesize()));
	if (size > g_map.max_size)
		return (-1);
	*map = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (*map == MAP_FAILED)
		return (-1);
	g_map.max_size -= size;
	header = new_header(map, size, prev, bsize);
	if (prev)
		prev->next = header;
	return (0);
}

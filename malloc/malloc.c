/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:50:50 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:50:51 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/resource.h>
#include "libft/libft.h"
#include "malloc.h"

t_maps			g_map = {NULL, NULL, NULL, 0, 0, 0};

static void		*find_free_space(int bsize, size_t size, void **map)
{
	t_header	*header;
	t_block		*block;

	header = (t_header *)*map;
	while (header)
	{
		block = (t_block *)header->first;
		while (block && (void *)block + block->next <= header->end)
		{
			if (block->flag == FREE && block->next >= size)
				return (set_block(bsize, size, block, header->end));
			if ((void *)block + block->next == header->end)
				block = NULL;
			else
				block = (void *)block + block->next;
		}
		if (!header->next)
		{
			if (new_map(bsize, map, header) < 0)
				return (NULL);
		}
		else
			header = header->next;
	}
	return (NULL);
}

static void		init_glob(void)
{
	struct rlimit	rlp;

	g_map.size_tiny = TINY;
	g_map.size_small = SMALL;
	if (!getrlimit(RLIMIT_DATA, &rlp))
		g_map.max_size = rlp.rlim_cur;
}

void			*set_block(int bsize, size_t size, t_block *block, void *end)
{
	t_block		*tmp;
	size_t		len;

	tmp = NULL;
	if ((unsigned int)bsize > g_map.size_tiny)
		len = size + g_map.size_tiny + sizeof(t_block);
	else
		len = size + sizeof(t_block);
	if ((unsigned int)bsize > g_map.size_small || block->next < len)
		size = block->next;
	else
	{
		tmp = (void *)block + size;
		tmp->prev = size;
		tmp->next = block->next - size;
		tmp->flag = FREE;
		if ((void *)tmp + tmp->next + sizeof(t_block) < end)
		{
			tmp = (void *)tmp + tmp->next;
			tmp->prev = block->next - size;
		}
	}
	block->next = size;
	block->flag = USED;
	return (block);
}

void			*malloc(size_t size)
{
	void		*ptr;

	size = 0 ? 1 : size;
	if (!g_map.tiny && !g_map.small && !g_map.large)
		init_glob();
	if (size + sizeof(t_header) > g_map.max_size || size > g_map.max_size)
		return (NULL);
	size += sizeof(t_block);
	if (size - sizeof(t_block) <= g_map.size_tiny)
	{
		if (!g_map.tiny && new_map(g_map.size_tiny, &g_map.tiny, NULL) < 0)
			return (NULL);
		ptr = find_free_space(g_map.size_tiny, size, &g_map.tiny);
	}
	else if (size - sizeof(t_block) <= g_map.size_small)
	{
		if (!g_map.small && new_map(g_map.size_small, &g_map.small, NULL) < 0)
			return (NULL);
		ptr = find_free_space(g_map.size_small, size, &g_map.small);
	}
	else
		ptr = large_alloc(size, &g_map.large);
	if (ptr)
		ptr = (void *)ptr + sizeof(t_block);
	return (ptr);
}

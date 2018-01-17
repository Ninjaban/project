/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:50:26 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:50:27 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static void		free_ptr(t_header *head, t_block *ptr, t_block *end, size_t len)
{
	if ((ptr == head->first && end) || (ptr != head->first && end))
	{
		ptr->next = len;
		end->prev = len;
		ptr->flag = FREE;
		ft_bzero((void *)ptr + sizeof(t_block), len - sizeof(t_block));
		g_map.max_size += len;
	}
	else if (ptr != head->first && !end)
	{
		ptr->next = len;
		ptr->flag = FREE;
		ft_bzero((void *)ptr + sizeof(t_block), len - sizeof(t_block));
		g_map.max_size += len;
	}
	else if (ptr == head->first && !end)
	{
		ptr->next = head->size - sizeof(t_header) - 1;
		ptr->flag = FREE;
		if (head->prev || head->next)
			clear_map(head);
	}
	return ;
}

static void		defrag_map(t_header *header, t_block *block)
{
	t_block		*tmp;
	size_t		size;

	block->flag = FREE;
	tmp = block;
	while (tmp->flag == FREE && tmp->prev)
		tmp = (void *)tmp - tmp->prev;
	if (tmp->flag == FREE)
		block = tmp;
	else
		block = (void *)tmp + tmp->next;
	tmp = block;
	size = 0;
	while (tmp->flag == FREE)
	{
		size += tmp->next;
		tmp = (void *)tmp + tmp->next;
		if ((void *)tmp >= header->end)
			return (free_ptr(header, block, NULL, size));
	}
	return (free_ptr(header, block, tmp, size));
}

int				check_pointer(t_header *header, t_block *block)
{
	t_block		*tmp;

	tmp = header->first;
	while ((void *)tmp < header->end)
	{
		if (tmp == block)
			return (1);
		tmp = (void *)tmp + tmp->next;
	}
	return (0);
}

t_header		*check_header(t_block *block)
{
	t_header	*header;

	header = (t_header *)g_map.tiny;
	while (header)
	{
		if ((void *)block > (void *)header && (void *)block < header->end)
			return (header);
		header = header->next;
	}
	header = (t_header *)g_map.small;
	while (header)
	{
		if ((void *)block > (void *)header && (void *)block < header->end)
			return (header);
		header = header->next;
	}
	header = (t_header *)g_map.large;
	while (header)
	{
		if ((void *)block > (void *)header && (void *)block < header->end)
			return (header);
		header = header->next;
	}
	return (NULL);
}

void			free(void *ptr)
{
	t_block		*block;
	t_header	*header;

	if (!ptr)
		return ;
	block = (void *)ptr - sizeof(t_block);
	header = check_header(block);
	if (!header)
		return ;
	if (!check_pointer(header, block))
		return ;
	if (header->format > SMALL)
		free_large(header, block);
	else
		defrag_map(header, block);
	return ;
}

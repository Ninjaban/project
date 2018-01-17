/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:51:35 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:36 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static size_t	check_format(size_t size)
{
	if (size && size <= TINY)
		return (TINY);
	if (size > TINY + 1 && size <= SMALL)
		return (SMALL);
	return (0);
}

static void		*change_block(t_block *block, t_header *header, size_t size)
{
	void		*tmp;
	size_t		block_len;

	block_len = sizeof(t_block);
	if (block->next - block_len <= TINY)
		tmp = set_block(TINY, size + block_len, block, header->end);
	else if (block->next - block_len <= SMALL)
		tmp = set_block(SMALL, size + block_len, block, header->end);
	else
		return (NULL);
	return (tmp + block_len);
}

void			*realloc(void *ptr, size_t size)
{
	t_header	*header;
	t_block		*block;
	void		*tmp;

	if (!ptr && !size)
		return (NULL);
	if (!ptr)
		return (malloc(size));
	if (!size)
		size = 1;
	block = ptr - sizeof(t_block);
	header = check_header(block);
	if (!header || !check_pointer(header, block))
		return (NULL);
	if (header->format != check_format(size)
		|| size + sizeof(t_block) > block->next)
	{
		tmp = malloc(size);
		if (size > block->next - sizeof(t_block))
			size = block->next - sizeof(t_block);
		ft_memcpy(tmp, ptr, size);
		free(ptr);
		return (tmp);
	}
	return (change_block(block, header, size));
}

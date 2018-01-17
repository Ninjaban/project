/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:51:42 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:43 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static void		puthexa(size_t dec)
{
	size_t		i;

	if (dec)
	{
		i = dec / 16;
		puthexa(i);
		if (dec % 16 < 10)
			ft_putchar('0' + dec % 16);
		else
			ft_putchar('a' + (dec % 16) - 10);
	}
	else
		ft_putstr("0x");
	return ;
}

static void		print_map(char *name, t_header *header)
{
	ft_putstr(name);
	ft_putstr(" : ");
	puthexa((size_t)header);
	ft_putchar('\n');
}

static void		loop_maps(t_header *header, char *name)
{
	t_block		*block;

	while (header)
	{
		print_map(name, header);
		block = header->first;
		while (block)
		{
			if (block->flag == USED)
			{
				puthexa(((size_t)(void *)block + sizeof(t_block)));
				ft_putstr(" - ");
				puthexa(((size_t)(void *)block + block->next));
				ft_putstr(" : ");
				ft_putnbr(block->next - sizeof(t_block));
				ft_putchar('\n');
			}
			block = (void *)block + block->next;
			if ((void *)block + 1 >= header->end)
				block = NULL;
		}
		header = header->next;
	}
}

void			show_alloc_mem(void)
{
	if (g_map.tiny)
		loop_maps((t_header *)g_map.tiny, "TINY");
	if (g_map.small)
		loop_maps((t_header *)g_map.small, "SMALL");
	if (g_map.large)
		loop_maps((t_header *)g_map.large, "LARGE");
	return ;
}

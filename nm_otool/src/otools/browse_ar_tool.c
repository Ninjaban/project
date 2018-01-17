/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_ar_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:06 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:41:07 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static void			print_ar_tool(uint32_t off, char *ptr, char *file)
{
	int				size;
	struct ar_hdr	*arch;
	char			*name;

	arch = (void*)ptr + off;
	name = catch_name(arch->ar_name);
	size = catch_size(arch->ar_name);
	ft_putchar('\n');
	ft_putstr(file);
	ft_putchar('(');
	ft_putstr(name);
	ft_putchar(')');
	ft_putstr(":\n");
	do_otool((void*)arch + sizeof(*arch) + size, file);
}

void				browse_ar_tool(t_offlist *lst, char *ptr, char *name)
{
	t_offlist		*tmp;

	tmp = lst;
	while (tmp)
	{
		print_ar_tool(tmp->off, ptr, name);
		tmp = tmp->next;
	}
}

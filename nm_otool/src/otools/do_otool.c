/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:35 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:41:36 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void					do_otool(void *mem, char *name)
{
	struct mach_header_64	*mo;
	struct load_command		*com;
	unsigned int			number;

	mo = mem;
	com = mem + sizeof(struct mach_header_64);
	number = *(int *)mem;
	if (number == MH_MAGIC_64)
		browse_cmd(com, mo);
	else if (number == FAT_MAGIC || number == FAT_CIGAM)
		do_fat_tool(mem);
	else if (!ft_strncmp(mem, ARMAG, SARMAG))
		do_archive_tool(mem, name);
	else
		ft_putendl("Wrong binary format");
}

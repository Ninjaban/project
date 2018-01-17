/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fat_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:25 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:41:25 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void					do_fat_tool(char *ptr)
{
	struct fat_header	*fat;
	struct fat_arch		*arch;
	uint32_t			x;
	uint32_t			offset;

	fat = (void*)ptr;
	x = fat->nfat_arch;
	x = swap_uint32(x);
	arch = (void*)ptr + sizeof(fat);
	while (x)
	{
		if (swap_uint32(arch->cputype) == CPU_TYPE_X86_64)
			offset = arch->offset;
		arch += sizeof(arch) / sizeof(void*);
		x--;
	}
	do_otool(ptr + swap_uint32(offset), NULL);
}

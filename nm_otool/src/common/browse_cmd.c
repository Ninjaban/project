/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:27:52 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:27:58 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

static void						check_text(\
		struct segment_command_64 *seg, struct mach_header_64 *mo)
{
	struct section_64			*sec;
	unsigned int				i;

	i = 0;
	sec = (struct section_64*)\
	(seg + sizeof(struct segment_command_64*) / sizeof(void*));
	while (i < seg->nsects)
	{
		if (!ft_strcmp(sec->sectname, TUT) && !ft_strcmp(sec->segname, TXT))
		{
			write(1, "(__TEXT,__text) section\n", 24);
			display_res(sec->addr, sec->size, (char *)mo + sec->offset);
		}
		sec = (struct section_64*)(((void*)sec) + sizeof(struct section_64));
		i++;
	}
}

static void						check_64(\
		struct load_command *com, struct mach_header_64 *mo)
{
	struct segment_command_64	*seg;

	seg = (struct segment_command_64*)com;
	check_text(seg, mo);
}

void							browse_cmd(\
			struct load_command *com, struct mach_header_64 *mo)
{
	unsigned int				i;

	i = 0;
	while (i < mo->ncmds)
	{
		if (com->cmd == LC_SEGMENT_64)
			check_64(com, mo);
		com += com->cmdsize / sizeof(void *);
		i++;
	}
}

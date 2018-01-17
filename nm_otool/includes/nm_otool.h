/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:25:59 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:59:12 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H
# include "../libft/libft.h"
# include <sys/mman.h>
# include <fcntl.h>
# include <ar.h>
# include <sys/stat.h>
# include <mach-o/ranlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# define TXT "__TEXT"
# define TUT "__text"

void		do_nm(char *ptr, char *name);
void		do_fat(char *ptr);
void		do_archive(char *ptr, char *name);
void		browse_ar_nm(t_offlist *lst, char *ptr, char *name);
char		typing(uint32_t type, uint32_t n_sect, t_lsection *sec, int addr);
t_lsection	*get_section(struct load_command *cmd, struct mach_header_64 *mo);
t_memlist	*add_elem(\
			t_memlist *e, struct nlist_64 l, char *s, t_lsection *sec);
void		end_nm(struct symtab_command *sym, char *ptr, t_lsection *sec);

void		do_otool(void *mem, char *name);
void		do_fat_tool(char *ptr);
void		do_archive_tool(void *ptr, char *name);
void		browse_ar_tool(t_offlist *lst, char *ptr, char *name);

int			catch_size(char *name);
char		*catch_name(char *name);
uint32_t	swap_uint32(uint32_t val);
void		display_res(long unsigned int addr, unsigned int size, char *ptr);
void		browse_cmd(struct load_command *com, struct mach_header_64 *mo);
t_offlist	*add_off(t_offlist *lst, uint32_t off, uint32_t strx);

#endif

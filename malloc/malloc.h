/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:50:59 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:00 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include "malloc_struct.h"

int			check_pointer(t_header *header, t_block *block);
t_header	*check_header(t_block *block);
void		free(void *ptr);
void		*set_block(int bsize, size_t size, t_block *block, void *end);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free_large(t_header *header, t_block *block);
void		*large_alloc(size_t size, void **map);
void		clear_map(t_header *header);
int			new_map(int bsize, void **map, t_header *prev);
void		show_alloc_mem(void);

#endif

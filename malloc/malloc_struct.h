/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:51:11 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/21 16:51:15 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

# define USED '0'
# define FREE '1'

# define TINY 512
# define SMALL 1500

typedef struct		s_bsizes
{
	unsigned int	tiny;
	unsigned int	small;
}					t_bsizes;

typedef struct		s_maps
{
	void			*tiny;
	void			*small;
	void			*large;
	unsigned int	size_tiny;
	unsigned int	size_small;
	size_t			max_size;
}					t_maps;

typedef struct		s_block
{
	unsigned int	prev;
	size_t			next;
	unsigned char	flag;
}					t_block;

typedef struct		s_header
{
	struct s_header	*next;
	struct s_header	*prev;
	struct s_block	*first;
	void			*end;
	unsigned int	format;
	size_t			size;
}					t_header;

t_maps				g_map;

#endif

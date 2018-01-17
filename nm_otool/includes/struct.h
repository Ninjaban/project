/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:27:14 by mmarchan          #+#    #+#             */
/*   Updated: 2016/01/28 15:59:54 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct stat		t_stat;

typedef struct			s_memlist
{
	long int			value;
	char				type;
	char				*str;
	struct s_memlist	*next;
	struct s_memlist	*prev;
}						t_memlist;

typedef struct			s_section
{
	char				*name;
	unsigned int		nb;
	struct s_section	*next;
}						t_section;

typedef struct			s_lsection
{
	t_section			*first;
	t_section			*last;
}						t_lsection;

typedef struct			s_offlist
{
	uint32_t			off;
	uint32_t			strx;
	struct s_offlist	*next;
	struct s_offlist	*prev;
}						t_offlist;

typedef struct			s_doarchive
{
	int					i;
	int					size;
	int					size2;
	int					cmd;
}						t_doarchive;

#endif

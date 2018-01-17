/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:21:58 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/26 15:47:18 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		end_line(char **line, char *retline, char *backline)
{
	if (*retline)
	{
		*line = ft_strdup(retline);
		if (backline)
			ft_bzero(backline, ft_strlen(backline));
		return (1);
	}
	return (0);
}

static int		fill_line(char **line, char *retline, int *i, int fd)
{
	if (*retline && fd >= 0 && BUFF_SIZE > 0)
	{
		while (retline[*i] != '\n' && retline[*i])
			*i += 1;
		*line = ft_strnew(*i);
		*line = ft_strncpy(*line, retline, *i);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			i;
	int			ret;
	char		*buffer;
	char		*retline;
	static char	*backline;

	i = 0;
	retline = ((backline) ? ft_strdup(backline) : ft_strnew(BUFF_SIZE));
	while (!ft_strchr(retline, '\n') && retline && fd >= 0 && BUFF_SIZE > 0)
	{
		if ((buffer = ft_strnew(BUFF_SIZE)))
		{
			if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
				retline = ft_strjoin(retline, buffer);
			else if (ret == 0)
				return (end_line(line, retline, backline));
			free(buffer);
		}
	}
	if (!fill_line(line, retline, &i, fd))
		return (-1);
	backline = ft_strsub(retline, i + 1, (ft_strlen(retline) - i));
	free(retline);
	return (1);
}

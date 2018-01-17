/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:11:20 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:17:28 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skipwhitespace(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (s);
}

int					ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		count;

	result = 0;
	sign = 1;
	count = 0;
	str = ft_skipwhitespace(str);
	if (str[count] == '-' && ft_isdigit(str[count + 1]) != 0)
	{
		sign = -1;
		count++;
	}
	if (str[count] == '+')
		count++;
	while (ft_isdigit(str[count]))
	{
		result = result * 10 + str[count] - 48;
		count++;
	}
	return (sign * result);
}

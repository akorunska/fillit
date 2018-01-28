/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:43:17 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/05 19:29:48 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int				i;
	unsigned int	temp;

	i = 0;
	if (n >= 0)
		temp = n;
	else
	{
		temp = -n;
		i = 1;
	}
	while ((temp /= 10) > 0)
		i++;
	return (i + 1);
}

static char	*myitoa(int n, int size)
{
	int				i;
	int				end;
	unsigned int	temp;
	char			*res;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = size - 1;
	res[size] = '\0';
	end = 0;
	temp = n;
	if (n < 0)
	{
		res[0] = '-';
		temp = -n;
		end = 1;
	}
	while (i >= end)
	{
		res[i] = (temp % 10) + 48;
		temp /= 10;
		i--;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;

	size = count_size(n);
	res = myitoa(n, size);
	return (res);
}

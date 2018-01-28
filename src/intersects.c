/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:49:25 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/24 15:51:11 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overflows_bottom(int f_size, t_tetramino *t, int shift)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (t->coordinates[i] + shift >= f_size * f_size)
			return (1);
		i++;
	}
	return (0);
}

int		ints_right(int f_size, t_tetramino *t, int shift)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((t->coordinates[i] + shift + 1) % f_size == 0)
			return (1);
		i++;
	}
	return (0);
}

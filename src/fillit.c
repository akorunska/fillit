/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:01:33 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/24 15:51:05 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		insert_tetr(char *field, t_tetramino *tetr, int shift)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (field[tetr->coordinates[i] + shift] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		field[tetr->coordinates[i] + shift] = tetr->letter;
		i++;
	}
	return (1);
}

void	clear_field(char *field, t_tetramino *tetr, int shift)
{
	int i;

	i = 0;
	while (i < 4)
	{
		field[tetr->coordinates[i] + shift] = '.';
		i++;
	}
}

int		fillit(char *field, t_tetramino **tetrs, int f_size, int to_insert)
{
	int		i;
	int		j;
	int		ins;

	if (!tetrs[to_insert])
		return (1);
	i = -1;
	while (++i < f_size)
	{
		j = -1;
		while (++j < f_size)
		{
			ins = insert_tetr(field, tetrs[to_insert], j + i * f_size);
			if (ins == 1 && fillit(field, tetrs, f_size, to_insert + 1))
				return (1);
			else if (ins == 1)
				clear_field(field, tetrs[to_insert], j + i * f_size);
			if (ints_right(f_size, tetrs[to_insert], j + i * f_size))
				break ;
		}
		if (overflows_bottom(f_size, tetrs[to_insert], i * f_size))
			break ;
	}
	return (0);
}

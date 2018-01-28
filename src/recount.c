/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recount.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:44:33 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/24 09:29:43 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	recount(t_tetramino **tetrs, int from)
{
	int			cur;
	int			coord;
	int			j;

	cur = 0;
	while (tetrs[cur])
	{
		j = 0;
		while (j < 4)
		{
			coord = tetrs[cur]->coordinates[j];
			tetrs[cur]->coordinates[j] += coord / from;
			j++;
		}
		cur++;
	}
}

void	recount_minimise(t_tetramino **tetrs, int from)
{
	int			cur;
	int			coord;
	int			j;

	cur = 0;
	while (tetrs[cur])
	{
		j = 0;
		while (j < 4)
		{
			coord = tetrs[cur]->coordinates[j];
			tetrs[cur]->coordinates[j] -= coord / from;
			j++;
		}
		cur++;
	}
}

void	recount_to(t_tetramino **tetrs, int from, int to)
{
	int			cur;
	int			coord;
	int			j;

	cur = 0;
	while (tetrs[cur])
	{
		j = 0;
		while (j < 4)
		{
			coord = tetrs[cur]->coordinates[j];
			tetrs[cur]->coordinates[j] += coord / from * (to - from);
			j++;
		}
		cur++;
	}
}

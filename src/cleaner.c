/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:21:20 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/24 16:23:17 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void	free_tetrs(t_tetramino **t)
{
	int i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
	t = NULL;
}

int		free_tetrsi(t_tetramino **t)
{
	free_tetrs(t);
	return (0);
}

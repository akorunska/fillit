/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:35:08 by ddenkin           #+#    #+#             */
/*   Updated: 2017/11/23 22:39:29 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_if_square(t_tetramino *tetr)
{
	if (tetr->coordinates[0] == 0 && tetr->coordinates[1] == 1\
			&& tetr->coordinates[2] == 4 && tetr->coordinates[3] == 5)
		return (1);
	return (0);
}

int		check_if_line(t_tetramino *tetr)
{
	if (tetr->coordinates[0] == 0 && tetr->coordinates[1] == 1\
			&& tetr->coordinates[2] == 2 && tetr->coordinates[3] == 3)
		return (1);
	if (tetr->coordinates[0] == 0 && tetr->coordinates[1] == 4\
			&& tetr->coordinates[2] == 8 && tetr->coordinates[3] == 12)
		return (1);
	return (0);
}

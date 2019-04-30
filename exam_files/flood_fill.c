/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:06:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/30 09:12:20 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	actual_flood_fill(char **tab, char colour, t_point size, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= size.x || y >= size.y)
		return ;
	tab[x][y] = 'F';
	actual_flood_fill(tab, colour, size, x + 1, y);
	actual_flood_fill(tab, colour, size, x, y + 1);
	actual_flood_fill(tab, colour, size, x - 1, y);
	actual_flood_fill(tab, colour, size, x, y - 1);

}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	actual_flood_fill(tab, tab[begin.y][begin.x], size, begin.x, begin.y);
}

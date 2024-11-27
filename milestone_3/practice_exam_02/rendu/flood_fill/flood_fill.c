/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:23:58 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 16:26:55 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	flood_fill_recursive(char **tab, t_point size, t_point pos, char target)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return ;
	if (tab[pos.y][pos.x] != target)
		return ;
	tab[pos.y][pos.x] = 'F';
	flood_fill_recursive(tab, size, (t_point){pos.x + 1, pos.y}, target);
	flood_fill_recursive(tab, size, (t_point){pos.x - 1, pos.y}, target);
	flood_fill_recursive(tab, size, (t_point){pos.x, pos.y + 1}, target);
	flood_fill_recursive(tab, size, (t_point){pos.x, pos.y - 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	if (target == 'F')
		return ;
	flood_fill_recursive(tab, size, begin, target);
}

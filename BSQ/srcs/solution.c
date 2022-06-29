/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:16:54 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 13:45:36 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_tab_dim	g_dimensions;
t_mapchar	g_tab_caracters;

int	check_obstacle(char **tab, int row, int col, int size)
{
	int	i;

	if (row + size >= g_dimensions.rows || col + size >= g_dimensions.columns)
		return (0);
	i = 0;
	while (i < size)
	{
		if ((col + i < g_dimensions.columns && tab[row + size][col
				+ i] == g_tab_caracters.obs) || (row + i < g_dimensions.rows
				&& tab[row + i][col + size] == g_tab_caracters.obs))
		{
			return (0);
		}
		i++;
	}
	if (tab[row + i][col + i] == g_tab_caracters.obs)
		return (0);
	return (1);
}

void	apply_square(char **tab, t_point_max p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p.max_size)
	{
		j = 0;
		while (j < p.max_size)
		{
			tab[p.row + i][p.column + j] = g_tab_caracters.full;
			j++;
		}
		i++;
	}
}

void	find_square(char **tab, t_point_max *max_square)
{	
	int			i;
	int			j;
	int			size;

	i = 0;
	while (i < g_dimensions.rows)
	{
		j = 0;
		while (j < g_dimensions.columns)
		{
			size = 0;
			while (tab[i][j] != g_tab_caracters.obs && check_obstacle(tab, i, j,
					size))
				size++;
			if (size > max_square->max_size)
			{
				max_square->max_size = size;
				max_square->row = i;
				max_square->column = j;
			}
			j++;
		}
		i++;
	}
	apply_square(tab, *max_square);
}

char	**find_biggest_square(char **tab, t_tab_dim dims, t_mapchar cars)
{
	t_point_max	square_point;

	g_dimensions = dims;
	g_tab_caracters = cars;
	square_point.max_size = 0;
	square_point.row = 0;
	square_point.column = 0;
	find_square(tab, &square_point);
	return (tab);
}

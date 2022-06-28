/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:16:54 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 00:43:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/structs.h"

t_tab_dim dimensions;
t_tab_caracters tab_caracters;

int check_obstacle(char **tab,int row, int col, int size)
{
	int i;

	if (row + size >= dimensions.rows	|| col + size >= dimensions.columns)
		return (0);
	
	i = 0;
	while (i < size)
	{	
		if ((col + i < dimensions.columns && tab[row + size][col + i] == tab_caracters.obstacle ) 
				|| (row + i < dimensions.rows && tab[row + i][col + size] == tab_caracters.obstacle) ) 
		{
	
			return (0);
		}
		i++;
	}
	if (tab[row + i][col + i] == tab_caracters.obstacle )
		return (0);
	return (1);
}

char **apply_square(char **tab,t_point_max p)
{
	int i;
	int j;
	
	printf("%c", tab_caracters.full);
	i = p.row;
	j = p.column;
	while (i < p.row + p.max_size)
	{	
		while (j < p.column + p.max_size)
		{
			printf("tab[%d][%d] == %c \n",i,j,tab[i][j]);
			tab[i][j] = tab_caracters.full;
			printf("tab[%d][%d] == %c \n",i,j,tab[i][j]);
			tab[i][j] = tab_caracters.full;
			
			j++;
		}
		i++;
	}
	return tab;
}


char **find_biggest_square(char **tab, t_tab_dim dims, t_tab_caracters cars)
{
	int	i;
	int	j;
	int	size;
	t_point_max square_point;

	dimensions = dims;
	tab_caracters = cars;
	square_point.max_size = 0;
	square_point.row = 0;
	square_point.column = 0;
	i = 0;
	while (i < dimensions.rows)
	{
		j = 0;
		while (j < dimensions.columns)
		{
			size = 0;
			while ( tab[i][j] != tab_caracters.obstacle && check_obstacle(tab, i , j , size) )
				size++;
			if (size > square_point.max_size)
			{
				square_point.max_size = size ;
				square_point.row = i ;
				square_point.column = j;
			}
			j++;
		}
		i++;
	}
	return  apply_square(tab,square_point);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:05:59 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 00:11:43 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/structs.h"

char **random_table(t_tab_caracters p,int row,int col)
{
	char	**s ;
	int 	i;
	int		j;

	i = 0;
	s = (char **)malloc(row * sizeof(char *));
	while (i < row)
	{
		s[i] = (char *)malloc( col  * sizeof(char));
		j = 0;
		while (j < col)
		{
			s[i][j] = ( rand() % 2  == 0 ? p.obstacle : p.empty);
			j++;
		}
		i++;
	}
	return s;
}


void	display_table(char **tab,int row ,int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%c ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


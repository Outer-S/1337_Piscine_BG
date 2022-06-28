/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:33:52 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 00:45:00 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/structs.h"

char 	**find_biggest_square(char **tab, t_tab_dim dims, t_tab_caracters cars);
char 	**random_table(t_tab_caracters p, int row, int col);
void	display_table(char **tab, int row, int col);

int main(int argc, char **argv)
{
	char  **s;
	t_tab_caracters x;
	x.empty = '.';
	x.obstacle = '-';
	x.full = 'x';
	
	t_tab_dim d;
	d.rows =atoi(argv[1]) ;
	d.columns = atoi(argv[1]);

	if (argc)
	{
		s = random_table(x ,d.rows, d.columns);
		display_table(s,d.rows,d.columns);
		find_biggest_square(s,d,x);
		display_table(s, d.rows, d.columns );
	}

}

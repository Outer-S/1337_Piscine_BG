/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:05:59 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 11:39:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	display_table(char **tab, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}

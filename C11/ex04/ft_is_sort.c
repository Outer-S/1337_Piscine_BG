/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:29:39 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/30 16:21:39 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	res;
	int	sort_desc;

	i = 0;
	sort_desc = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			res = f(tab[i], tab[j]);
			if (res != 0 && sort_desc == 0)
				sort_desc = res;
			else if (sort_desc < 0 && res > 0)
				return (0);
			else if (sort_desc > 0 && res < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

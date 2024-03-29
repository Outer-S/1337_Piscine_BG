/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:01:41 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/30 20:05:46 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab != 0)
	{
		if (f(*tab) != 0)
			return (1);
		tab++;
	}
	return (0);
}

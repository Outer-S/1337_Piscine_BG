/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:28:06 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/30 18:19:27 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putnbr(i / 10);
		ft_putchar('8');
	}
	else if (i < 0)
	{
		ft_putchar('-');
		ft_putnbr(-i);
	}
	else
	{
		if (i > 9)
		{
			ft_putnbr(i / 10);
		}
		ft_putchar('0' + i % 10);
	}
}

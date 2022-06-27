/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:25:38 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/15 16:56:48 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_loop(char a, char b, char c)
{
	while (a <= '7')
	{
		ft_putchar(a, b, c);
		if (c == '9')
		{
			b++;
			c = b;
		}
		if (b == '9')
		{	
			a++;
			b = a;
			b++;
			c = b;
		}
		if (a == '7')
		{
			ft_putchar('7', '8', '9');
			break ;
		}
		c++;
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '1';
	c = '2';
	ft_loop(a, b, c);
}

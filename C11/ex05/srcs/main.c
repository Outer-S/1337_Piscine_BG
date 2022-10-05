/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:38:34 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/30 19:00:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_op(int x, char op, int y, void (**f)(int, int))
{
	if (op == '+')
		f[0](x, y);
	else if (op == '-')
		f[1](x, y);
	else if (op == '/')
		f[2](x, y);
	else if (op == '%')
		f[3](x, y);
	else
		ft_putstr("0");
}

int	main(int ac, char **av)
{
	char	op;
	int		x;
	int		y;
	void	(*f[4])(int, int);

	f[0] = ft_add;
	f[1] = ft_substract;
	f[2] = ft_div;
	f[3] = ft_mod;
	if (ac == 4)
	{
		x = ft_atoi(av[1]);
		op = av[2][0];
		y = ft_atoi(av[3]);
		print_op(x, op, y, f);
		ft_putstr("\n");
	}
	return (0);
}

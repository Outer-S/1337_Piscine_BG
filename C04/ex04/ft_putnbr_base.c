/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:53:58 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/18 16:59:28 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_validity(char *c, int size)
{
	int	i;
	int	j;

	i = 0;
	if (c[0] == '\0' || size == 1)
		return (0);
	while (c[i] != '\0')
	{
		j = i + 1;
		while (c[j] != '\0')
		{
			if (c[j] == c[i])
				return (0);
			j++;
		}
		if (c[i] == '-' || c[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_base(long nb, char *base, long base_len)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_put_base(-nb, base, base_len);
	}
	else if (nb < base_len)
	{
		ft_putchar(base[nb % base_len]);
	}
	else
	{
		ft_put_base(nb / base_len, base, base_len);
		ft_putchar(base[nb % base_len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_len;
	long	nb;

	nb = (long)nbr;
	base_len = (long)ft_strlen(base);
	if (ft_check_validity(base, base_len))
		ft_put_base(nb, base, base_len);
}

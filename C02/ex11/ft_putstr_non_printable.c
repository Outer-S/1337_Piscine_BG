/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:01 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/15 20:26:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex_value(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[(c / 16)]);
	ft_putchar("0123456789abcdef"[(c % 16)]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ft_str_is_printable(*str))
		{
			ft_hex_value((unsigned char)*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

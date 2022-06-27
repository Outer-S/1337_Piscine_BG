/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:33:39 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/18 02:10:07 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ' )
		return (1);
	return (0);
}

int	ft_isnumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isplusminus(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	p;
	int	res;

	p = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_isplusminus(*str))
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	while (ft_isnumeric(*str))
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	res *= p;
	return (res);
}

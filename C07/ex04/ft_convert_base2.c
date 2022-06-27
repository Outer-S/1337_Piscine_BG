/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:10:31 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/25 17:33:28 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i] && base[i] != '\0')
	{
		i++;
	}
	if (base[i] == '\0')
		return (-1);
	return (i);
}

long	ft_atoi(char *str, char *base, long base_len)
{
	long	p;
	long	res;

	p = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	res = 0;
	while (ft_find_in_base(*str, base) >= 0)
	{
		res *= base_len;
		res += ft_find_in_base(*str, base);
		str++;
	}
	return (res * p);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *c, int size)
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
		if (c[i] == '\t' || c[i] == '\n' || c[i] == '\v' || c[i] == '\f'
			|| c[i] == '\r' || c[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base, long base_len)
{
	long	res;

	base_len = ft_strlen(base);
	res = (long) ft_atoi(str, base, base_len);
	return (res);
}

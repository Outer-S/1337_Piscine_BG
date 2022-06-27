/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:40:55 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/25 18:18:13 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, long base_len);
int		ft_strlen(char *c);
int		ft_check_base(char *c, int size);

int	ft_init_char(int nb, int base_len)
{
	int	alloc_len;

	alloc_len = 1;
	if (nb == -2147483648)
		alloc_len += ft_init_char(nb / base_len, base_len);
	else if (nb < 0)
		alloc_len += ft_init_char(-nb, base_len);
	else if (nb >= base_len)
		alloc_len += ft_init_char(nb / base_len, base_len);
	else
		return (1);
	return (alloc_len);
}

char	*ft_strcat(char *dest, char src)
{
	int	i;

	i = ft_strlen(dest);
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_put_base(long nb, char *base, long base_len, char *res)
{
	if (nb == -2147483648)
	{
		ft_put_base(nb / base_len, base, base_len, res);
		ft_put_base(-(nb % base_len), base, base_len, res);
	}
	if (nb < 0)
	{
		res[0] = '-';
		res[1] = '\0';
		ft_put_base(-nb, base, base_len, res);
	}
	else if (nb < base_len)
	{
		return (ft_strcat(res, base[nb % base_len]));
	}
	else
	{
		ft_put_base(nb / base_len, base, base_len, res);
		ft_strcat(res, base[nb % base_len]);
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_base_from;
	int		base_from_len;
	int		base_to_len;
	char	*res;

	base_from_len = ft_strlen(base_from);
	base_to_len = ft_strlen(base_to);
	if (!ft_check_base(base_from, base_from_len) || !ft_check_base(base_to,
			base_to_len))
		return (0);
	nbr_base_from = ft_atoi_base(nbr, base_from, base_from_len);
	res = (char *)malloc((ft_init_char(nbr_base_from, base_to_len) + 1)
			* sizeof(char));
	res[0] = '\0';
	ft_put_base(nbr_base_from, base_to, base_to_len, res);
	return (res);
}

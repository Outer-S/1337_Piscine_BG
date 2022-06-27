/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:11:42 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/25 19:50:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

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

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}

int	count_strings_lengths(int size, char **strs, int sep_len)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i + 1 != size)
			total += sep_len;
		i++;
	}
	return (total + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		res_len;
	int		sep_len;
	int		i;

	sep_len = ft_strlen(sep);
	res_len = count_strings_lengths(size, strs, sep_len);
	res = (char *)malloc(res_len * sizeof(char));
	if (!res)
		return (0);
	res[0] = '\0';
	if (size == 0)
		return (res);
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i + 1 != size)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

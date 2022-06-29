/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:27:11 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 00:27:14 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
		i++;
	while (src[c] != '\0')
	{
		dest[i + c] = src[c];
		c++;
	}
	dest[i + c] = '\0';
	return (dest);
}

int	ft_atoi(char *str, char *empty, char *obs, char *full)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	len = ft_strlen(str);
	if (len < 4)
		return (-1);
	while (str[i] && i + 3 < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = 10 * n + str[i] - '0';
		else
			return (-1);
		i++;
	}
	*empty = str[i];
	*obs = str[i + 1];
	*full = str[i + 2];
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:28:20 by messoull          #+#    #+#             */
/*   Updated: 2022/06/26 23:28:23 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>

int	count_elem(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '\n')
			cnt++;
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	if (str[i] == '\n')
		return (-1);
	return (cnt);
}

char	*ft_strcpy_valid(char *dest, char *src, t_mapchar supp, int flag)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0' && src[i] != '\n')
	{
		if (flag && (src[i] != supp.emp && src[i] != supp.obs))
		{
			dest = 0;
			return (0);
		}
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(char *src, int *i, t_mapchar supp, int flag)
{
	int		len;
	char	*dest;

	while (*src && *src == '\n')
	{
		src++;
		(*i) += 1;
	}
	len = 0;
	while (src[len] != '\0' && src[len] != '\n')
		len++;
	*i += len;
	dest = (char *)malloc(len + 1);
	dest = ft_strcpy_valid(dest, src, supp, flag);
	return (dest);
}

void	init_struct_parse(t_parsed_file *parsed_struct, char **list, int nb,
		t_mapchar *supp)
{
	parsed_struct->str = list;
	parsed_struct->dim.rows = nb;
	parsed_struct->dim.columns = ft_strlen(list[0]);
	parsed_struct->cars = *supp;
}

int	split(char *str, t_parsed_file *parsed_struct)
{
	char		**list;
	int			nb;
	int			i;
	int			j;
	t_mapchar	*supp;

	supp = malloc(sizeof(t_mapchar));
	nb = count_elem(str) - 1;
	i = 0;
	j = 0;
	if (nb < 1 || ft_parse_first(ft_strdup(str + i, &i, *supp, 0), supp) != nb)
		return (1);
	list = (char **)malloc((nb + 1) * sizeof(char *));
	list[nb] = 0;
	while (j < nb)
	{
		list[j] = ft_strdup(str + i, &i, *supp, 1);
		if (list[j] == 0)
			return (1);
		j++;
	}
	init_struct_parse(parsed_struct, list, nb, supp);
	return (0);
}

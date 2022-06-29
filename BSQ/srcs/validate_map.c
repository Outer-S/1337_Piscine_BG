/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:27:19 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 00:27:28 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	ft_str_is_printable(char str)
{
	if (str < ' ' || str > '~')
		return (0);
	return (1);
}

int	ft_is_valid_char(char empty, char obs, char full)
{
	if (empty == obs || empty == full || obs == full)
	{
		return (0);
	}
	if (ft_str_is_printable(empty) && ft_str_is_printable(obs)
		&& ft_str_is_printable(full))
	{
		return (1);
	}
	return (0);
}

int	ft_parse_first(char *str, t_mapchar *supp)
{
	int	nb;

	nb = ft_atoi(str, &(*supp).emp, &(*supp).obs, &(*supp).full);
	if (nb < 0)
		return (-1);
	else
	{
		if (ft_is_valid_char((*supp).emp, (*supp).obs, (*supp).full))
			return (nb);
		else
		{
			return (-1);
		}
	}
}

int	validate_len(char **list)
{
	int	i;
	int	len;

	i = 0;
	while (list[i] != 0)
	{
		if (i == 0)
			len = ft_strlen(list[0]);
		else if (len != ft_strlen(list[i]))
			return (1);
		i++;
	}
	return (0);
}

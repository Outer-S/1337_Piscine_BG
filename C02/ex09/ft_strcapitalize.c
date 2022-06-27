/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:49:27 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/15 09:04:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char str)
{
	if (str < 48 || str > 57)
		return (0);
	return (1);
}

int	ft_str_is_alpha(char str)
{
	if ((str < 97 || str > 122) && (str < 65 || str > 90))
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char str)
{
	if (str < 97 || str > 122)
		return (0);
	return (1);
}

void	ft_capitalizer(char *str, int *cap_next_alpha)
{
	while (*str)
	{
		if (ft_str_is_alpha(*str))
		{
			if (ft_str_is_numeric(*(str - 1)) && *cap_next_alpha)
				*cap_next_alpha = 0;
			if (ft_str_is_lowercase(*str) && *cap_next_alpha)
			{
				*str = *str - 32;
				*cap_next_alpha = 0;
			}
			else if (*cap_next_alpha)
				*cap_next_alpha = 0;
			else if (!ft_str_is_lowercase(*str) && !(*cap_next_alpha))
				*str = *str + 32;
		}
		else
			*cap_next_alpha = 1;
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{	
	int		cap_next_alpha;
	char	*reset;

	cap_next_alpha = 1;
	reset = str;
	ft_capitalizer(str, &cap_next_alpha);
	return (reset);
}

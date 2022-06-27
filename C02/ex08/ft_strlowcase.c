/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:22:52 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/14 18:33:28 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*reset;

	reset = str;
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str = *str + 32;
		}
		str++;
	}
	return (reset);
}

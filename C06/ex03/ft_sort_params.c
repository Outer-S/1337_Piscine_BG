/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:08:12 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/21 21:08:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	u_s1;
	unsigned char	u_s2;

	while (*s1 != '\0' || *s2 != '\0')
	{
		u_s1 = (unsigned char) *s1;
		u_s2 = (unsigned char) *s2;
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		s1++;
		s2++;
	}
	return (0);
}

void	sort_args(char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}	
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{	
	int	i;

	i = 1;
	sort_args(argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}

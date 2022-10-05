/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:18:46 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/30 20:52:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	u_s1;
	unsigned char	u_s2;

	while (*s1 != '\0' || *s2 != '\0')
	{
		u_s1 = (unsigned char)*s1;
		u_s2 = (unsigned char)*s2;
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
}

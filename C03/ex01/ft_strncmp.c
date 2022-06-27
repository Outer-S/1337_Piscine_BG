/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:24:42 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/16 10:16:36 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	u_s1;
	unsigned char	u_s2;
	unsigned int	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		u_s1 = (unsigned char)*s1;
		u_s2 = (unsigned char)*s2;
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		s1++;
		s2++;
		i++;
	}	
	return (0);
}

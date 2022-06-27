/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:06:33 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/16 10:09:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

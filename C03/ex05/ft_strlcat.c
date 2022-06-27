/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:43:42 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/17 13:52:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len ;
	unsigned int	s_len ;
	unsigned int	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len >= size || size == 0)
		return (size + s_len);
	i = 0;
	while (i < size - d_len - 1 && *(src + i) != '\0')
	{
		*(dest + d_len + i) = *(src + i);
		i++;
	}
	*(dest + d_len + i) = '\0';
	return (d_len + s_len);
}

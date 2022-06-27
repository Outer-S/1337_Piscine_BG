/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:00:25 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/12 03:15:34 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	looper;

	looper = 'a';
	while (looper <= 'z')
	{
		write(1, &looper, 1);
		looper++;
	}
}

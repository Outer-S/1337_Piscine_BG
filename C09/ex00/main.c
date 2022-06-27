/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:47 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/27 14:15:50 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int main()
{
	ft_putchar('c');
	int i = 0;
	int j = 10;
	ft_swap(&i,&j);
	ft_putstr("hello brahim \n");
	ft_strlen("abc");
	ft_strcmp("abc","abcd");
	return (0);
}

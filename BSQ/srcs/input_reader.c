/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:47:21 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 18:47:24 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*strip_buff(char *buff)
{
	char	*temp;
	int		len;

	len = ft_strlen(buff);
	temp = malloc(len + 1);
	temp[0] = 0;
	temp = ft_strcpy(temp, buff);
	free(buff);
	return (temp);
}

char	*copy_and_realocate(char *buff, int *size, int all)
{
	char	*temp;
	char	*sp;

	*size *= 2;
	temp = malloc(*size + 1 + all);
	temp[0] = 0;
	temp = ft_strcpy(temp, buff);
	sp = buff;
	buff = temp;
	free(sp);
	return (temp);
}

char	*read_one_line(int fd, int all)
{
	char	curr;
	char	*buff;
	int		size;
	int		i;

	i = all;
	size = 500;
	buff = malloc(size + 1 + all);
	buff[0] = '\n';
	while (read(fd, &curr, 1))
	{
		if (!all && curr == '\n')
			break ;
		if (i >= size)
			buff = copy_and_realocate(buff, &size, all);
		buff[i] = curr;
		i++;
	}
	buff[i] = 0;
	buff = strip_buff(buff);
	return (buff);
}

char	*concat_list(char **s_list)
{
	int		total;
	int		i;
	char	*all_str;

	total = 0;
	i = 0;
	while (s_list[i] != 0)
	{
		total += ft_strlen(s_list[i]);
		i++;
	}
	all_str = malloc(total + 1);
	all_str[0] = 0;
	i = 0;
	while (s_list[i] != 0)
	{
		all_str = ft_strcat(all_str, s_list[i]);
		i++;
	}
	return (all_str);
}

char	*read_input(void)
{
	char		*line;
	int			lignes;
	int			i;
	char		**list;
	t_mapchar	*supp;

	line = read_one_line(0, 0);
	lignes = 1;
	i = 1;
	supp = malloc(sizeof(t_mapchar));
	lignes = ft_parse_first(line, supp);
	list = (char **)malloc((1 + 2) * sizeof(char *));
	list[2] = 0;
	list[0] = line;
	list[1] = read_one_line(0, 1);
	line = concat_list(list);
	return (line);
}

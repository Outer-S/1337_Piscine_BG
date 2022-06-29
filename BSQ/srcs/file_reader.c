/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:25:33 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 00:25:39 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(char *file_name)
{
	char	buf[21];
	int		rd_cnt;
	int		total_len;
	int		f;
	char	*all_str;

	total_len = 0;
	f = open(file_name, O_RDONLY);
	if (f == -1)
		return (0);
	rd_cnt = read(f, buf, 20);
	while (rd_cnt)
	{
		total_len += rd_cnt;
		rd_cnt = read(f, buf, 20);
	}
	all_str = (char *)malloc(total_len + 1);
	close(f);
	f = open(file_name, O_RDONLY);
	rd_cnt = read(f, all_str, total_len);
	all_str[total_len] = '\0';
	return (all_str);
}

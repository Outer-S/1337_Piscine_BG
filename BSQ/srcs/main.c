/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:33:52 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/29 12:04:18 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"
#include <stdlib.h>
#include <unistd.h>

void	print_error(void)
{
	write(2, "map error\n", 10);
}

void	user_input_read(void)
{
	int				flag;
	t_parsed_file	*parsed_file;

	parsed_file = malloc(sizeof(t_parsed_file));
	flag = get_from_user(parsed_file);
	if (flag == 1)
	{
		print_error();
		return ;
	}
	find_biggest_square(parsed_file->str, parsed_file->dim, parsed_file->cars);
	display_table(parsed_file->str, parsed_file->dim.rows);
	free(parsed_file);
}

void	file_input_read(int argc, char **argv)
{
	int				i;
	int				flag;
	t_parsed_file	*parsed_file;

	i = 1;
	flag = 0;
	while (argc > 1 && i < argc)
	{
		parsed_file = malloc(sizeof(t_parsed_file));
		flag = get_from_file(argv[i], parsed_file);
		if (flag == 1)
			print_error();
		else
		{
			find_biggest_square(parsed_file->str, parsed_file->dim,
				parsed_file->cars);
			display_table(parsed_file->str, parsed_file->dim.rows);
		}
		if (i != argc - 1)
			ft_putstr("\n");
		free(parsed_file);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int				i;
	int				flag;

	i = 1;
	flag = 0;
	if (argc == 1)
		user_input_read();
	else
		file_input_read(argc, argv);
}

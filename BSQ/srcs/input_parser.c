/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:47:05 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 18:47:09 by messoull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	input_parse_data(char *str, t_parsed_file *parsed_struct)
{
	int	flag;

	flag = 0;
	flag = split(str, parsed_struct);
	if (flag == 0)
		flag = validate_len(parsed_struct->str);
	return (flag);
}

int	get_from_user(t_parsed_file *parsed_struct)
{
	char	*str;

	str = read_input();
	if (str == 0)
		return (1);
	return (input_parse_data(str, parsed_struct));
}

int	get_from_file(char *filename, t_parsed_file *parsed_struct)
{
	char	*str;

	str = read_file(filename);
	if (str == 0)
		return (1);
	return (input_parse_data(str, parsed_struct));
}

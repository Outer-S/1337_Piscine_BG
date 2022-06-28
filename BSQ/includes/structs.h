/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:54:39 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/28 17:11:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#	define STRUCTS_H

typedef struct s_tab_dim
{
	int	rows;
	int columns;
} t_tab_dim;

typedef struct s_tab_caracters
{
	char empty;
	char obstacle;
	char full;
} t_tab_caracters;

typedef struct s_point_max
{
	int max_size;
	int row;
	int column;
} t_point_max;

#endif

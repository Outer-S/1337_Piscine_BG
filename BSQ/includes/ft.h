/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messoull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:27:52 by messoull          #+#    #+#             */
/*   Updated: 2022/06/29 12:50:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_tab_dim
{
	int			rows;
	int			columns;
}				t_tab_dim;

typedef struct s_point_max
{
	int			max_size;
	int			row;
	int			column;
}				t_point_max;

typedef struct s_mapchar
{
	char		emp;
	char		obs;
	char		full;
}				t_mapchar;

typedef struct s_parsed_file
{
	char		**str;
	t_tab_dim	dim;
	t_mapchar	cars;
}				t_parsed_file;

// Solution Functions
char			**find_biggest_square(char **tab, t_tab_dim dims,
					t_mapchar cars);
// Random Solutions
void			display_table(char **tab, int row);
// Validate file
int				split(char *str, t_parsed_file *parsed_struct);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_atoi(char *str, char *empty, char *obs, char *full);
int				ft_is_valid_char(char empty, char obs, char full);
int				ft_parse_first(char *str, t_mapchar *supp);
int				validate_len(char **list);
char			*ft_strcpy(char *dest, char *src);
char			*read_input(void);
char			*ft_strcat(char *dest, char *src);
int				get_from_user(t_parsed_file *parsed_struct);
int				get_from_file(char *filename, t_parsed_file *parsed_struct);
char			*read_file(char *file_name);

#endif

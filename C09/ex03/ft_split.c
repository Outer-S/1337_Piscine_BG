/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:24:22 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/27 18:31:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_occurences(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_seperator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check_seperator(str[i], charset))
			i++;
	}
	return (count + 1);
}

int	split_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_seperator(str[i], charset))
		i++;
	return (i);
}

int	make_split(char **loc, char *str, char *charset)
{
	int		i;
	char	*split;
	int		next;
	int		len;

	len = split_len(str, charset);
	split = (char *)malloc((len + 1) * sizeof(char));
	if (!split)
		return (0);
	next = 0;
	while (loc[next] != 0)
		next++;
	i = 0;
	while (i < len)
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
	loc[next] = split;
	loc[next + 1] = 0;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	int		i;
	int		step;

	i = 0;
	splits = (char **)malloc(count_occurences(str, charset) * sizeof(char *));
	if (!splits)
		return (0);
	splits[0] = 0;
	while (str[i])
	{
		while (str[i] && check_seperator(str[i], charset))
			i++;
		if (str[i])
		{
			step = make_split(splits, &str[i], charset);
			if (step == 0)
				return (0);
			i += step;
		}
	}
	return (splits);
}

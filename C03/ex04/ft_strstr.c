/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:48:43 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/16 17:07:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_find(char *str, char *to_find, char *res, int *j)
{
	if (*to_find != '\0' && *str == *to_find && *j == 0)
	{
		res = str;
		*j += 1;
	}
	else if (*to_find != '\0' && *str == *to_find)
		*j += 1;
	else if (*to_find != '\0' && *str != *to_find)
	{
		*j = 0;
		return ((char *)0);
	}
	else if (*to_find == '\0')
		return (res);
	return (res);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[0] != '\0')
	{
		while (str[i] != '\0')
		{
			result = ft_find(&str[i], &to_find[j], result, &j);
			if (result && to_find[j] == '\0' )
				return (result);
			i++;
		}
		return ((char *)0);
	}
	return (str);
}

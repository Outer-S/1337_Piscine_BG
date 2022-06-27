/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:21:39 by bamrouch          #+#    #+#             */
/*   Updated: 2022/06/21 15:55:28 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define N 10

int	positve_diag(int board[][N], int row, int col)
{
	int	i;
	int	j;

	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 1)
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	q_is_safe(int board[][N], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		if (board[row][i])
			return (0);
		i++;
	}
	if (positve_diag(board, row, col) == 1)
		return (0);
	i = row;
	j = col;
	while (i < N && j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i++;
		j--;
	}
	return (1);
}

void	print_solutions(int board[][N])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[j][i] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	recurse_queen(int board[N][N], int col)
{
	int	i;
	int	count;

	count = 0;
	if (col == N)
	{
		print_solutions(board);
		return (1);
	}
	i = 0;
	while (i < N)
	{
		if (q_is_safe(board, i, col) == 1)
		{
			board[i][col] = 1;
			count += recurse_queen(board, col + 1);
			board[i][col] = 0;
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	board[N][N];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (recurse_queen(board, 0));
}

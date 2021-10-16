/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:45:04 by dirony            #+#    #+#             */
/*   Updated: 2021/10/16 21:33:04 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combo(int combo[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(combo[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_available(int x, int y, int combo[10])
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (combo[i] == y)
			return (0);
		if ((x - i == y - combo[i]) || (x - i == combo[i] - y))
			return (0);
		i++;
	}
	return (1);
}

int	put_queens(int column, int combo[10], int counter)
{
	int	j;

	if (column == 10)
	{
		print_combo (combo);
		counter++;
		return (counter);
	}
	j = 0;
	while (j < 10)
	{
		if (is_available (column, j, combo))
		{
			combo[column] = j;
			counter = put_queens (column + 1, combo, counter);
		}
		j++;
	}
	return (counter);
}

int	ft_ten_queens_puzzle(void)
{
	int	combo[10];
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (i < 10)
	{
		combo[i] = -1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		combo[0] = i;
		counter = put_queens(1, combo, counter);
		i++;
	}
	return (counter);
}

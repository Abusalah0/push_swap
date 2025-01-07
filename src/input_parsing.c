/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:38:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 20:38:24 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
	{
		return (0);
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	parse_string_numbers(char **input, int *numbers, int size)
{
	int		i;
	long	num;

	i = 0;
	while (i < size)
	{
		if (!is_valid_input(input[i + 1]))
		{
			free(numbers);
			error_exit("ERROR\n");
		}
		num = ft_atol(input[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(numbers);
			error_exit("ERROR\n");
		}
		numbers[i] = num;
		i++;
	}
}
/*
** check_for_input:
**----------------
** Check if there are any duplicates/none numeric/out of range values in the input
** using a hashset to store the values and check for duplicates.
** return an array of integers if the input is valid.
*/
int	*check_input(int argc, char **argv)
{
	int	*numbers;
	int	size;

	if (argc < 2)
	{
		error_exit("ERROR\n");
	}
	size = argc - 1;
	numbers = malloc(size * sizeof(int));
	if (!numbers)
	{
		error_exit("ERROR\n");
	}
	parse_string_numbers(argv, numbers, size);
	if (check_for_dups(numbers, size))
	{
		free(numbers);
		error_exit("ERROR\n");
	}
	return (numbers);
}

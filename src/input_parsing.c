/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:38:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:38:53 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static unsigned int	hash(int key, unsigned int size)
{
	if (key < 0)
		return (-key % size);
	return (key % size);
}

static bool	check_for_dups(int *nums, int nums_size)
{
	int				i;
	unsigned int	setsize;
	int				*hashset;
	unsigned int	index;

	i = -1;
	setsize = nums_size * 2 + 1;
	hashset = ft_calloc(setsize, sizeof(int));
	if (!hashset)
		return (true);
	while (++i < nums_size)
	{
		index = hash(nums[i], setsize);
		while (hashset[index] != 0)
		{
			if (hashset[index] == nums[i])
			{
				free(hashset);
				return (true);
			}
			index = (index + 1) % setsize;
		}
		hashset[index] = nums[i];
	}
	free(hashset);
	return (false);
}

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
			error_exit("ERROR\n", 0, 0);
		}
		num = ft_atol(input[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(numbers);
			error_exit("ERROR\n", 0, 0);
		}
		numbers[i] = num;
		i++;
	}
}

int	*check_input(int argc, char **argv)
{
	int	*numbers;
	int	size;

	if (argc < 2)
		error_exit("Error\n", NULL, 0);
	size = argc - 1;
	numbers = malloc(size * sizeof(int));
	if (!numbers)
		error_exit("Error\n", NULL, 0);
	parse_string_numbers(argv, numbers, size);
	if (check_for_dups(numbers, size))
	{
		free(numbers);
		error_exit("Error\n", NULL, 0);
	}
	return (numbers);
}

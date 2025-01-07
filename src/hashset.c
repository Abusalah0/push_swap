/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:18:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 19:40:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static unsigned int	hash(int key, unsigned int size)
{
	if (key < 0)
		return (-key % size);
	return (key % size);
}

static int	insert(int *hashset, unsigned int size, int value)
{
	unsigned int	index;

	index = hash(value, size);
	while (hashset[index] != 0)
	{
		if (hashset[index] == value)
		{
			return (true);
		}
		index = (index + 1) % size;
	}
	hashset[index] = value;
	return (false);
}

bool	check_for_dups(int *nums, int nums_size)
{
	int				i;
	unsigned int	setsize;
	int				*hashset;

	i = -1;
	setsize = nums_size * 2 + 1;
	hashset = ft_calloc(setsize, sizeof(int));
	if (!hashset)
		return (true);
	while (++i < nums_size)
	{
		if (insert(hashset, setsize, nums[i]))
		{
			free(hashset);
			return (true);
		}
	}
	free(hashset);
	return (false);
}

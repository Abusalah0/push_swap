/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:18:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:29:10 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static unsigned int	hash(int key, unsigned int size)
{
	if (key < 0)
		return (-key % size);
	return (key % size);
}

static bool	insert(long *hashset, unsigned int size, int value)
{
	unsigned int	index;

	index = hash(value, size);
	while (hashset[index] != EMPTY_SLOT)
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

bool	ft_check_for_dups(int *nums, int nums_size)
{
	int		setsize;
	long	*hashset;
	int		i;

	i = -1;
	setsize = nums_size * 2 + 1;
	hashset = malloc(setsize * sizeof(long));
	if (!hashset)
		return (true);
	while (++i < setsize)
		hashset[i] = EMPTY_SLOT;
	i = 0;
	while (i < nums_size)
	{
		if (insert(hashset, setsize, nums[i]))
		{
			free(hashset);
			return (true);
		}
		i++;
	}
	free(hashset);
	return (false);
}

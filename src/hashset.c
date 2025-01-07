/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:18:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 19:19:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static unsigned int	hash(int key, unsigned int size)
{
	if (key < 0)
		return (-key % size);
	return (key % size);
}

bool	check_for_dups(int *nums, int nums_size)
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

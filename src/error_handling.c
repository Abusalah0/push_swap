/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:56:57 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/05 21:14:53 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(char *str, void **allocated_mem, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (allocated_mem[i])
			free(allocated_mem[i]);
		i++;
	}
	if (allocated_mem)
		free(allocated_mem);
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_stack(t_item *stack)
{
	t_item	*cursor;

	if (!stack)
		return ;
	cursor = stack;
	while (cursor)
	{
		cursor = stack;
		stack = stack->next;
		free(cursor);
	}
}

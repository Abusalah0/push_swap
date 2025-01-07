/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:56:57 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 17:31:16 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_stack(t_item *stack)
{
	t_item	*cursor;

	while (stack)
	{
		cursor = stack;
		stack = stack->next;
		free(cursor);
	}
}

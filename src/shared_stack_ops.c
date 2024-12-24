/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_stack_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:14:04 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/24 01:01:10 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop(t_item **stack)
{
	t_item	*temp1;
	t_item	*temp2;

	if (!stack || !(*stack))
		return ;
	temp1 = top(*stack);
	temp2 = temp1;
	temp2 = temp2->prev;
	if (temp2)
		temp2->next = NULL;
	free(temp1);
}

int	push(t_item **stack, int val)
{
	t_item	*new_node;
	t_item * temp;
	
	new_node = malloc(sizeof(t_item));
	if (!new_node)
		return (0);
	new_node->val = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*stack))
	{
		*stack = new_node;
	}
	else
	{
		temp = top(*stack);
		new_node->prev = temp;
		temp->next = new_node;
	}
	return (1);
}

void	print_stack(t_item *stack)
{
	t_item *cursor;

	if (!stack)
	{
		printf("Stack is empty.\n");
		return;
	}
	cursor = stack;
	while (cursor)
	{
		printf("Index: %d | Value: %d\n", cursor->index, cursor->val);
		cursor = cursor->next;
	}
	printf("End of stack.\n");
}

void fill_stack(t_item **stack, int *numbers, int size)
{
    int i;

    i = size;
    while (--i >= 0)
    {
        if (!push(stack, numbers[i]))
        {
            free_stack(*stack);
            free(numbers);
            exit(EXIT_FAILURE);
        }
        
    }
}
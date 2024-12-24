/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:29:27 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 19:11:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>


// Node structure for a doubly linked list
typedef struct s_item
{
	int val;             // Value of the node
	int	index;
	int push_cost;
	bool above_median;
	bool	cheapest;
	struct s_item	*target;
	struct s_item *next; // Pointer to the next node
	struct s_item *prev; // Pointer to the previous node
}		t_item;

//necassery stack ops
void	pop(t_item **stack);
int	push(t_item **stack, int val);

// stack info
void	print_stack(t_item *stack);
t_item  *get_max(t_item *stack);
t_item  *get_min(t_item *stack);
t_item	*top(t_item *stack);
int		get_size(t_item *stack);
bool	is_sorted(t_item* stack);
t_item  *get_cheapest(t_item *stack);

// stack a ops
int	pa(t_item **stack_a, t_item **stack_b);
int	sa(t_item **stack);
int	ra(t_item **stack);
int rra(t_item **stack);

// stack b ops
int		sb(t_item **stack);
int		pb(t_item **stack_b, t_item **stack_a);
int		rb(t_item **stack);
int		rrb(t_item **stack);
// parallel ops
int		ss(t_item **stack_a, t_item **stack_b);
int		rr(t_item **stack_a, t_item **stack_b);
int		rrr(t_item **stack_a, t_item **stack_b);


// error and memory
void 	error_exit(char *str, void *allocated_mem[], int i);
void	free_split(char **nums);
void    free_stack(t_item *stack);


// input
int		*check_input(int argc, char **argv);
void	fill_stack(t_item **stack, int *numbers, int size);

// node ops
void    set_node_index(t_item *stack);
void    set_target_node(t_item *a_stack, t_item *b_stack);
void    set_cheapest(t_item *stack);
void cost_analysis(t_item *a_stack, t_item *b_stack);


// sorting 

void sort_three(t_item **stack);
void    update_a(t_item *a_stack, t_item *b_stack);
void move_a_to_b(t_item **a_stack, t_item **b_stack);
void    turk_sort(t_item **a_stack, t_item **b_stack);
void    min_on_top(t_item **a_stack);
void    rev_rotate_both(t_item **a_stack, t_item **b_stack, t_item *cheapest);
void    rotate_both(t_item **a_stack, t_item **b_stack, t_item *cheapest);
void    prep_for_push(t_item **stack, t_item *cheapest, char name);
#endif
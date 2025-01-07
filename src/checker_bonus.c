#include "../include/push_swap.h"

bool execute_op(char *op, t_item **a_stack, t_item **b_stack)
{
    if (!ft_strcmp(op, "ra\n"))
        ra(a_stack, false);
    else if (!ft_strcmp(op, "sa\n"))
        sa(a_stack, false);
    else if (!ft_strcmp(op, "pa\n"))
        pa(a_stack, b_stack, false);
    else if (!ft_strcmp(op, "rra\n"))
        rra(a_stack, false);
    else if (!ft_strcmp(op, "rb\n"))
        rb(b_stack, false);
    else if (!ft_strcmp(op, "sb\n"))
        sb(b_stack, false);
    else if (!ft_strcmp(op, "pb\n"))
        pb(a_stack, b_stack, false);
    else if (!ft_strcmp(op, "rrb\n"))
        rrb(b_stack, false);
    else if (!ft_strcmp(op, "rrr\n"))
        rrr(a_stack, b_stack, false);
    else if (!ft_strcmp(op, "rr\n"))
        rr(a_stack, b_stack, false);
    else if (!ft_strcmp(op, "ss\n"))
        ss(a_stack, b_stack, false);
    else
        return false;
    return true;
}

void exec_and_check_ops(t_item **a_stack, t_item **b_stack)
{
    char *command;

    command = get_next_line(0);
    while (command)
    {
        if (!execute_op(command, a_stack, b_stack))
        {
            free(command);
            free_stack(*a_stack);
            free_stack(*b_stack);
            write(2, "Error\n", 6);
            exit(1);
        }
        free(command);
        command = get_next_line(0);
    }
}

void final_check(t_item *a_stack, t_item *b_stack)
{
    if (is_sorted(a_stack) && b_stack == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int argc, char **argv)
{
    int     *num;
    t_item  *a_stack = NULL;
    t_item  *b_stack = NULL;

    if (argc < 2)
        return (write(2, "Error\n", 6), 1);

    num = check_input(argc, argv);
    if (!num)
        return (write(2, "Error\n", 6), 1);

    fill_stack(&a_stack, num, argc - 1);
    free(num);

    exec_and_check_ops(&a_stack, &b_stack);
    final_check(a_stack, b_stack);

    // free_stack(a_stack);
    // free_stack(b_stack);
    return 0;
}

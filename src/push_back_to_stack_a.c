/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:21:49 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 15:50:33 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_pos_in_a(t_stack *a, int n)
{
	t_stack *current = a;
    int max = find_stack_min(a);
    int min = find_stack_max(a);
    int closest = min;

    // Iterate through the stack
    while (current != NULL)
    {
        if (current->nbr > max)
            max = current->nbr;
        if (current->nbr < min)
            min = current->nbr;
        if (current->nbr > n && current->nbr < closest)
            closest = current->nbr;
        current = current->next;
    }
    if (n > max)
        // Case 1: n is the new maximum
        return min;
    else if (n < min)
        // Case 2: n is the new minimum
        return min;
    else
        // Case 3: n is neither new maximum nor minimum
        return closest;
}

// int calc_pos_in_a2(t_stack *a, int n)
// {
// 	int closest = INT_MAX;
// 	int found = 0;

// 	while (a)
// 	{
// 		if (a->nbr > n && a->nbr < closest)
// 		{
// 			closest = a->nbr;
// 			found = 1;
// 		}
// 		a = a->next;
// 	}

// 	if (found)
// 		return closest;
// 	else
// 		return -1;
// }

void	execute_rotate_a(t_stack **a, int ops)
{
	if (ops < 0)
	{
		while (ops <0)
		{
			op_rra(a, NULL, 0);
			ops++;
		}	
	}
	else if (ops > 0)
	{
		while (ops)
		{
			op_ra(a, NULL, 0);
			ops--;
		}	
	}
}

int	calc_optimal_ops(t_stack *a, int n)
{
	int	ra;
	int	rra;

	ra = calc_rotation_cost(a, n);
	rra = calc_r_rotation_cost(a, n);
	// ft_printf("calc_optimal_ops: ra = %d rra = %d\n", ra, rra);
	if (ra <= rra)
		return (ra);
	return (-rra);
}

int	find_b_nbr_pos_in_a(t_stack *a, int n)
{
	int	closest;
	int	ops;
	t_stack	*tmp;

	tmp = a;
	closest = calc_pos_in_a(tmp, n);
    // ft_printf("find_b_nbr_pos_in_a: nbr %d should be above %d in B\n", n, closest);
	// return (closest);
	if (closest == tmp->nbr)
		return (0);
	else
	{
		ops = calc_optimal_ops(tmp, closest);
    	// ft_printf("find_b_nbr_pos_in_a: ops %d \n", ops);
		return (ops);
	}
}

void push_back_to_stack_a(t_stack **a, t_stack **b)
{
	int	ops;

	// ft_printf("push_back_to_stack_a START\n");
	while (ft_lstsize(*b) > 0)
	{
		ops = find_b_nbr_pos_in_a(*a, (*b)->nbr);
		execute_rotate_a(a, ops);
		op_pa(a, b, 0);
		// debug_print_stacks(*a, *b);
		// ft_printf("/\\\n");
	}
	// ft_printf("push_back_to_stack_a END\n");
}


// void push_back_to_stack_a1(t_stack **a, t_stack **b)
// {
// 	int	ops;

// 	while (ft_lstsize(*b) > 0)
// 	{
// 		// ft_printf("pushback, %d left to go\n", ft_lstsize(*b));
// 		if ((*b)->nbr > find_stack_max(*a))
// 		{
// 			// ft_printf("pushback: (*b)->nbr > find_stack_max(*a)\n");
// 			find_b_nbr_pos_in_a(*a, (*b)->nbr);
// 			op_rra(a, NULL, 0);
// 			op_pa(a, b, 0);
// 		}
// 		// else if ((*b)->nbr < find_stack_min(*a))
// 		// {
// 		// 	ft_printf("(*b)->nbr < find_stack_min(*a)\n");
// 		// 	op_pa(a, b, 0);

// 		// }
// 		else
// 		{
// 			ft_printf("else\n");
// 			ops = find_b_nbr_pos_in_a(*a, (*b)->nbr);
// 			execute_rotate_a(a, ops);
// 			op_pa(a, b, 0);
// 		}
// 		// debug_print_stacks(*a, *b);
// 	}
// }
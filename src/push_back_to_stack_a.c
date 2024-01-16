/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:21:49 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 16:28:39 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int calc_pos_in_a(t_stack *a, int n)
// {
// 	int found = 0;
// 	int	max;
// 	int	min;

// 	max = find_stack_max(a);
// 	min = find_stack_min(a);
// 	if (n > max)
// 		// should be pushed at the bottom?
// 	else if (n < min)
// 		return (min);
// 	else
// 	{

// 	}
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

int calc_pos_in_a(t_stack *a, int n)
{
	int closest = INT_MAX;
	int found = 0;

	while (a)
	{
		if (a->nbr > n && a->nbr < closest)
		{
			closest = a->nbr;
			found = 1;
		}
		a = a->next;
	}

	if (found)
		return closest;
	else
		return -1;
}

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
	if (ra <= rra)
		return (ra);
	return (-rra);
}

int	find_b_nbr_pos_in_a(t_stack *a, t_stack *b)
{
	int	closest;
	int	ops;
	t_stack	*tmp;

	tmp = a;
	ft_printf("find_b_nbr_pos_in_a: number %d\n", b->nbr);
	closest = calc_pos_in_a(tmp, b->nbr);
	ft_printf("find_b_nbr_pos_in_a: should be above%d\n", closest);
	if (closest == tmp->nbr)
		return (0);
	else
	{
		ops = calc_optimal_ops(tmp, closest);
		return (ops);
	}
}

void push_back_to_stack_a(t_stack **a, t_stack **b)
{
	int	ops;

	ft_printf("push_back_to_stack_a START\n");
	while (ft_lstsize(*b) > 0)
	{
	// if !nbr is in correct position
	ops = find_b_nbr_pos_in_a(*a, *b);
	if (ops != 0)
	// ft_printf("%d is in correct position %d\n", (*b)->nbr, find_b_nbr_pos_in_a(*a, *b));
		execute_rotate_a(a, ops);
	// fixstack a by rotating
	// pa
		op_pa(a, b, 0);
	}

	ft_printf("push_back_to_stack_a END\n");
}
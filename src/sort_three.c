/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:26 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 11:15:03 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (find_stack_min(*a) == (*a)->nbr && (!stack_is_sorted_asc(*a)))
	{
		op_rra(a, NULL, 0);
		op_sa(a, NULL, 0);
	}
	else if (find_stack_max(*a) == (*a)->nbr)
	{
		op_ra(a, NULL, 0);
		if (!stack_is_sorted_asc(*a))
			op_sa(a, NULL, 0);
	}
	else
	{
		if (find_nbr_index_in_stack(*a, find_stack_max(*a)) == 1)
			op_rra(a, NULL, 0);
		else if (!stack_is_sorted_asc(*a))
			op_sa(a, NULL, 0);
	}
}

void	sort_two(t_stack **a)
{
	t_stack	*top;
	t_stack	*bottom;

	top = *a;
	bottom = top->next;
	if (top->nbr > bottom->nbr)
		op_sa(a, NULL, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:26 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 11:57:38 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_with_last_three(t_stack **a, t_workflow *workflow)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = *a;
	middle = top->next;
	bottom = middle->next;
	if ((top->nbr < middle->nbr && middle->nbr > bottom->nbr) \
		|| (top->nbr > middle->nbr && top->nbr < bottom->nbr))
	{
		op_sa(a, NULL, 0);
		op_ra(a, NULL, 0);
	}
	else if (top->nbr > middle->nbr && middle->nbr < bottom->nbr)
		op_ra(a, NULL, 0);
	else if (top->nbr < middle->nbr && middle->nbr < bottom->nbr)
	{
		op_sa(a, NULL, 0);
		op_rra(a, NULL, 0);
	}
	if ((*a)->nbr > (*a)->next->nbr)
		op_sa(a, NULL, 0);
	// debug_print_stack(*a, 'a');
	(void)workflow;
}

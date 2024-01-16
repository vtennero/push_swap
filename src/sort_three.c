/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:26 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 15:58:00 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->nbr;
	middle = (*a)->next->nbr;
	bottom = (*a)->next->next->nbr;
	if (bottom > top && top > middle)
		op_sa(a, NULL, 0);
	else if (middle > top && top > bottom)
		op_rra(a, NULL, 0);
	else if (top > middle && bottom > middle)
	{
		op_ra(a, NULL, 0);
		op_sa(a, NULL, 0);
	}
	else if (middle > bottom && bottom > top)
	{
		op_rra(a, NULL, 0);
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

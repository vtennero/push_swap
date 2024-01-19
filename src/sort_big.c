/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:57:20 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:16:58 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) >= 5)
		op_pb(a, b, 0);
	op_pb(a, b, 0);
}

static void	sort_b(t_stack **a, t_stack **b, t_workflow *workflow)
{
	t_stack	*current;

	current = *a;
	workflow->next_nbr = current->nbr;
	while (ft_lstsize(*a) > 3)
	{
		while (current != NULL)
		{
			def_workflow_a_to_b(*a, *b, current->nbr, workflow);
			current = current->next;
		}
		workflow->pb = 1;
		optimize_workflow(workflow);
		execute_workflow(workflow, a, b);
		current = *a;
	}
}

static void	final_fixes(t_stack **a)
{
	int	min;
	int	ra;
	int	rra;

	min = find_stack_min(*a);
	ra = calc_rotation_cost(*a, min);
	rra = calc_r_rotation_cost(*a, min);
	if (ra < rra)
	{
		while (ra)
		{
			op_ra(a, NULL, 0);
			ra--;
		}
	}
	else
	{
		while (rra)
		{
			op_rra(a, NULL, 0);
			rra--;
		}
	}
}

static void	sort_a(t_stack **a, t_stack **b, t_workflow *workflow)
{
	t_stack	*current;

	current = *b;
	workflow->next_nbr = current->nbr;
	if (!stack_is_sorted_asc(*a))
		sort_three(a);
	while (ft_lstsize(*b) > 0)
	{
		while (current != NULL)
		{
			def_workflow_b_to_a(*a, *b, current->nbr, workflow);
			current = current->next;
		}
		workflow->pa = 1;
		optimize_workflow(workflow);
		execute_workflow(workflow, a, b);
		current = *b;
	}
	if (!stack_is_sorted_asc(*a))
		final_fixes(a);
}

int	sort_big(t_stack **a, t_stack **b)
{
	t_workflow	*workflow;

	workflow = init_workflow_struct();
	if (!workflow)
		return (0);
	if (!stack_is_sorted_asc(*a))
	{
		init_push(a, b);
		sort_b(a, b, workflow);
		sort_a(a, b, workflow);
	}
	free(workflow);
	workflow = NULL;
	return (1);
}

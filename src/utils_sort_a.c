/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:18:20 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:10:40 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_pos_in_a(t_stack *a, int n)
{
	t_stack	*current;
	int		max;
	int		min;
	int		closest;

	current = a;
	max = find_stack_min(a);
	min = find_stack_max(a);
	closest = min;
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
		return (min);
	else if (n < min)
		return (min);
	else
		return (closest);
}

static void	calc_r_costs_b_to_a(t_stack *a, t_stack *b, int n, t_rot_costs *c)
{
	int	a_closest_number;

	c->rb = calc_rotation_cost(b, n);
	c->rrb = calc_r_rotation_cost(b, n);
	a_closest_number = calc_pos_in_a(a, n);
	c->ra = calc_rotation_cost(a, a_closest_number);
	c->rra = calc_r_rotation_cost(a, a_closest_number);
}

int	def_workflow_b_to_a(t_stack *a, t_stack *b, int nbr, t_workflow *w)
{
	t_rot_costs			costs;
	int					min_cost;

	calc_r_costs_b_to_a(a, b, nbr, &costs);
	min_cost = find_best_combination(&costs);
	update_workflow(w, min_cost, nbr, &costs);
	return (0);
}

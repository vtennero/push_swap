/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:18:25 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:11:22 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_pos_in_b(t_stack *b, int n)
{
	t_stack		*current;
	int			max;
	int			min;
	int			closest;

	current = b;
	max = find_stack_min(b);
	min = find_stack_max(b);
	closest = min;
	while (current != NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		if (current->nbr < min)
			min = current->nbr;
		if (current->nbr < n && current->nbr > closest)
			closest = current->nbr;
		current = current->next;
	}
	if (n > max)
		return (max);
	else if (n < min)
		return (max);
	else
		return (closest);
}

static void	calc_r_costs_a_to_b(t_stack *a, t_stack *b, int n, t_rot_costs *c)
{
	int	b_closest_number;

	c->ra = calc_rotation_cost(a, n);
	c->rra = calc_r_rotation_cost(a, n);
	b_closest_number = calc_pos_in_b(b, n);
	c->rb = calc_rotation_cost(b, b_closest_number);
	c->rrb = calc_r_rotation_cost(b, b_closest_number);
}

int	def_workflow_a_to_b(t_stack *a, t_stack *b, int nbr, t_workflow *w)
{
	t_rot_costs			costs;
	int					min_cost;

	calc_r_costs_a_to_b(a, b, nbr, &costs);
	min_cost = find_best_combination(&costs);
	update_workflow(w, min_cost, nbr, &costs);
	return (0);
}

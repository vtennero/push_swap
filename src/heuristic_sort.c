/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:23 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:55 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_workflow* init_workflow_struct()
{
	t_workflow *new_struct;
	
	new_struct = (t_workflow*)ft_calloc(1, sizeof(t_workflow));
	if (new_struct)
		new_struct->op_cost = -1;
	return (new_struct);
}

int			calc_rotation_cost(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int			calc_r_rotation_cost(t_stack *stack, int nbr)
{
	t_stack *last;
		
	last = ft_lstlast(stack);
	int i;
	
	i = 1;
	while (last != NULL)
	{
		if (last->nbr == nbr)
			return (i);
		last = last->prev;
		i++;
	}
	return (-1);
}


int			find_nbr_position_in_b(t_stack *stack, int n)
{
t_stack *current = stack;
	int max = find_stack_min(stack);
	int min = find_stack_max(stack);
	int closest = min;

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
		return max;
	else if (n < min)
		return max;
	else
		return closest;
}

int find_minimum(int arr[4], int size) {
	int min;
	int i;
	
	min = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return min;
}

void	calc_rotation_costs(t_stack *a, t_stack *b, int n, t_rotation_costs *c)
{
	int	b_closest_number;

	c->ra = calc_rotation_cost(a, n);
	c->rra = calc_r_rotation_cost(a, n);
	b_closest_number = find_nbr_position_in_b(b, n);
	c->rb = calc_rotation_cost(b, b_closest_number);
	c->rrb = calc_r_rotation_cost(b, b_closest_number);
}

int	find_best_combination(t_rotation_costs costs)
{
	int	cost[4];

	cost[0] = ft_max(costs.ra, costs.rb);
	cost[1] = ft_max(costs.rra, costs.rrb);
	cost[2] = costs.ra + costs.rrb;
	cost[3] = costs.rra + costs.rb;
	return (find_minimum(cost, 4));
}

int	determine_min_cost_combination(t_rotation_costs costs, int minCost)
{
	int	combinations[4];
	int	i;

	combinations[0] = ft_max(costs.ra, costs.rb);
	combinations[1] = ft_max(costs.rra, costs.rrb);
	combinations[2] = costs.ra + costs.rrb;
	combinations[3] = costs.rra + costs.rb;
	i = 0;
	while (i < 4)
	{
		if (combinations[i] == minCost)
			return (i);
		i++;
	}
	return (-1);
}

void	update_workflow(t_workflow *w, int m_cost, int nbr, t_rotation_costs c)
{
	int	combination;

	combination = determine_min_cost_combination(c, m_cost);
	if (w->op_cost == -1 || m_cost < w->op_cost)
	{
		w->op_cost = m_cost;
		w->next_nbr = nbr;
		w->ra = 0;
		w->rb = 0;
		if (combination == 0)
		{
			w->ra = c.ra;
			w->rb = c.rb;
		}
		else if (combination == 1)
		{
			w->rra = c.rra;
			w->rrb = c.rrb;
		}
		else if (combination == 2)
		{
			w->ra = c.ra;
			w->rrb = c.rrb;
		}
		else if (combination == 3)
		{
			w->rra = c.rra;
			w->rb = c.rb;
		}
	}
}

int	calc_min_cost_for_number(t_stack *a, t_stack *b, int nbr, t_workflow *w)
{
	t_rotation_costs	costs;
	int					min_cost;

	calc_rotation_costs(a, b, nbr, &costs);
	min_cost = find_best_combination(costs);
	update_workflow(w, min_cost, nbr, costs);
	return (0);
}

void	find_cheapest_number(t_stack **a, t_stack **b, t_workflow *workflow)
{
	t_stack	*current;

	current = *a;
	workflow->next_nbr = current->nbr;
	while (ft_lstsize(*a) > 3)
	{
		while (current != NULL)
		{
			calc_min_cost_for_number(*a, *b, current->nbr, workflow);
			current = current->next;
		}
		workflow->pb = 1;
		optimize_workflow(workflow);
		execute_workflow(workflow, a, b);
		current = *a;
	}
}

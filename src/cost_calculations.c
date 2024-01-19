/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:17:59 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 15:09:53 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rotation_cost(t_stack *stack, int nbr)
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

int	calc_r_rotation_cost(t_stack *stack, int nbr)
{
	t_stack	*last;
	int		i;

	last = ft_lstlast(stack);
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

int	determine_min_cost_combination(t_rot_costs *costs, int min_cost)
{
	int	combinations[4];
	int	i;

	combinations[0] = ft_max(costs->ra, costs->rb);
	combinations[1] = ft_max(costs->rra, costs->rrb);
	combinations[2] = costs->ra + costs->rrb;
	combinations[3] = costs->rra + costs->rb;
	i = 0;
	while (i < 4)
	{
		if (combinations[i] == min_cost)
			return (i);
		i++;
	}
	return (-1);
}

static int	find_minimum(int arr[4], int size)
{
	int	min;
	int	i;

	min = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	find_best_combination(t_rot_costs *costs)
{
	int	cost[4];

	cost[0] = ft_max(costs->ra, costs->rb);
	cost[1] = ft_max(costs->rra, costs->rrb);
	cost[2] = costs->ra + costs->rrb;
	cost[3] = costs->rra + costs->rb;
	return (find_minimum(cost, 4));
}

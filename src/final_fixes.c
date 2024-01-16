/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_fixes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:15:20 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 14:12:44 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_in_stack(t_stack *a)
{
	int min = INT_MAX;

    while (a != NULL)
    {
        if (a->nbr < min)
            min = a->nbr;
        a = a->next;
    }

    return min;
}

int find_position_in_stack(t_stack *a, int target_number)
{
    int position = 0;

    while (a != NULL)
    {
        if (a->nbr == target_number)
            return position;

        a = a->next;
        position++;
    }

    return -1; // Return -1 if the number is not found in the stack
}

void	final_fixes(t_stack **a)
{
	int	min;
	// int	pos;
	int	ops;
	// find min
	min = find_min_in_stack(*a);
	// find min position in stack
	// else 
	if ((*a)->nbr != min)
	{
		// pos = find_position_in_stack(a, min);
	// calc rotation and reverse rotation cost
		ops = calc_optimal_ops(*a, min);
		execute_rotate_a(a, ops);
	}
	// if 0 do nothing

}
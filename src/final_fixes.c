/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_fixes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:15:20 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/17 16:04:16 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_fixes(t_stack **a)
{
	int	min;
	int	ops;

	min = find_stack_min(*a);
	if ((*a)->nbr != min)
	{
		ops = calc_optimal_ops(*a, min);
		execute_rotate_a(a, ops);
	}
}

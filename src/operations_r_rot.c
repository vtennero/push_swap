/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:16:06 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:48 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrr(t_stack **a, t_stack **b, int j)
{
	op_rra(a, b, j + 1);
	op_rrb(a, b, j + 1);
	write(1, "rrr\n", 4);
}

void	op_rra(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (j == 0)
		write(1, "rra\n", 4);
	(void)b;
}

void	op_rrb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
	if (j == 0)
		write(1, "rrb\n", 4);
	(void)a;
}

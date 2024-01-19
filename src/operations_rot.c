/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:23:04 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:27 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rr(t_stack **a, t_stack **b, int j)
{
	op_ra(a, b, j + 1);
	op_rb(a, b, j + 1);
	write(1, "rr\n", 3);
}

void	op_ra(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	tmp->prev = *a;
	*a = tmp->next;
	(*a)->prev = NULL;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
	(void)b;
}

void	op_rb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	tmp->prev = *b;
	*b = tmp->next;
	(*b)->prev = NULL;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
	(void)a;
}

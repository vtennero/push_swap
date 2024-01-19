/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:15 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:13 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ss(t_stack **a, t_stack **b, int j)
{
	op_sa(a, b, j + 1);
	op_sb(a, b, j + 1);
	write(1, "ss\n", 3);
}

void	op_sa(t_stack **a, t_stack **b, int j)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*a = second;
	if (j == 0)
		write(1, "sa\n", 3);
	(void)b;
}

void	op_sb(t_stack **a, t_stack **b, int j)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *b;
	second = first->next;
	third = second->next;
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*b = second;
	if (j == 0)
		write(1, "sb\n", 3);
	(void)a;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:23:04 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/15 13:16:47 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	w_op_swap(t_stack **a, t_stack **b, int j)
{
	if (j == 0)
	{
		op_swap_list(a);
		write(1, "sa\n", 3);
	}
	else if (j == 1)
	{
		op_swap_list(b);
		write(1, "sb\n", 3);

	}
	else if (j == 2)
	{
		op_swap_list(a);
		op_swap_list(b);
		write(1, "ss\n", 3);
	}
}

void	w_op_rotate(t_stack **a, t_stack **b, int j)
{
	if (j == 0)
	{
		op_rotate_list(a);
		write(1, "ra\n", 3);
	}
	else if (j == 1)
	{
		op_rotate_list(b);
		write(1, "rb\n", 3);

	}
	else if (j == 2)
	{
		op_rotate_list(a);
		op_rotate_list(b);
		write(1, "rr\n", 3);
	}
}

void	w_op_rev_rotate(t_stack **a, t_stack **b, int j)
{
	if (j == 0)
	{
		op_reverse_rotate_list(a);
		write(1, "rra\n", 4);
	}
	else if (j == 1)
	{
		op_reverse_rotate_list(b);
		write(1, "rrb\n", 4);

	}
	else if (j == 2)
	{
		op_reverse_rotate_list(a);
		op_reverse_rotate_list(b);
		write(1, "rrr\n", 4);
	}
}

void	w_op_push(t_stack **a, t_stack **b, int j)
{
	if (j == 0)
	{
		op_push_to_list(a, b);
		write(1, "pa\n", 3);
	}
	else if (j == 1)
	{
		op_push_to_list(b, a);
		write(1, "pb\n", 3);
	}
}

void	op_push_to_list(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!*a)
        return;

    tmp = *a;
    *a = tmp->next;
    if (*a)
        (*a)->prev = NULL;
    tmp->next = *b;
    if (*b)
        (*b)->prev = tmp;
    *b = tmp;
}

void	op_rotate_list(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = ft_lstlast(*head);
	(*head)->next = tmp;
	tmp->prev = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

void	op_reverse_rotate_list(t_stack **head)
{
	t_stack *tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
}

void	op_swap_list(t_stack **head)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	second = first->next;
	third = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*head = second;
}
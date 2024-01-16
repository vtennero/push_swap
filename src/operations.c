/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:23:04 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/16 14:55:17 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ss(t_stack **a, t_stack **b, int j)
{
	op_sa(a, b, j + 1);
	op_sb(a, b, j + 1);
	write(1, "ss\n", 3);
}

void	op_rr(t_stack **a, t_stack **b, int j)
{
	op_ra(a, b, j + 1);
	op_rb(a, b, j + 1);
	write(1, "rr\n", 3);
}

void	op_rrr(t_stack **a, t_stack **b, int j)
{
	op_rra(a, b, j + 1);
	op_rrb(a, b, j + 1);
	write(1, "rrr\n", 4);
}

void	op_ra(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;                  // Save the current head of the list
    *a = ft_lstlast(*a);       // Move *a to the last element
    (*a)->next = tmp;          // The next of the last element is now the old head
    tmp->prev = *a;            // Update prev of the old head
    *a = tmp->next;            // *a now points to the second element
    (*a)->prev = NULL;         // The new head's prev is NULL
    tmp->next = NULL;          // The old head's next is now NULL
	if (j == 0)
		write(1, "ra\n", 3);
	(void)b;
}

void	op_rb(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*b || !(*b)->next)
        return ;
    tmp = *b;                  // Save the current head of the list
    *b = ft_lstlast(*b);       // Move *b to the last element
    (*b)->next = tmp;          // The next of the last element is now the old head
    tmp->prev = *b;            // Update prev of the old head
    *b = tmp->next;            // *b now points to the second element
    (*b)->prev = NULL;         // The new head's prev is NULL
    tmp->next = NULL;          // The old head's next is now NULL
	if (j == 0)
		write(1, "rb\n", 3);
	(void)a;
}


void	op_sa(t_stack **a, t_stack **b, int j)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *a;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*a = second; // Update the a of the list
	if (j == 0)
		write(1, "sa\n", 3);
	(void)b;
}

void	op_sb(t_stack **a, t_stack **b, int j)
{
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *b;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*b = second; // Update the a of the list
	if (j == 0)
		write(1, "sb\n", 3);
	(void)a;
}

void	op_rra(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

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
	t_stack *tmp;

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

void	op_pa(t_stack **a, t_stack **b, int j)
{
    t_stack *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = tmp->next;
    if (*b)
        (*b)->prev = NULL;
    tmp->next = *a;
    if (*a)
        (*a)->prev = tmp;
    *a = tmp;
	write(1, "pa\n", 3);
	j += 0;
}

void op_pb(t_stack **a, t_stack **b, int j)
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
    write(1, "pb\n", 3);
	j += 0;
}
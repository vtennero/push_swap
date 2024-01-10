/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:23:04 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/10 16:35:30 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	op_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	op_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	op_rr(t_stack **a, t_stack **b)
{
	op_ra(a, 0);
	op_rb(b, 0);
	write(1, "rr\n", 3);
}

void	op_sa(t_stack **head, int j)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *head;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*head = second; // Update the head of the list
	if (j == 0)
		write(1, "sa\n", 3);
}

void	op_sb(t_stack **head, int j)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return; // No swap needed if the list is empty or has only one element

	t_stack *first = *head;
	t_stack *second = first->next;
	t_stack *third = second->next;

	// Swapping process
	second->prev = first->prev; // In this case, first->prev is NULL
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;

	*head = second; // Update the head of the list
	if (j == 0)
		write(1, "sb\n", 3);
}

void	op_ss(t_stack **a, t_stack **b)
{
	op_sa(a, 0);
	op_sb(b, 0);
	write(1, "ss\n", 3);
}

void	op_rra(t_stack **a, int j)
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
}

void	op_rrb(t_stack **a, int j)
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
}

void	op_rrr(t_stack **a, t_stack **b)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	op_pa(t_stack **a, t_stack **b)
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
}

void op_pb(t_stack **a, t_stack **b)
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
}

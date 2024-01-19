/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:32:08 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:15:39 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_stack_max(t_stack *stack)
{
	int		max_nbr;
	t_stack	*current;

	if (stack == NULL)
		return (-1);
	max_nbr = stack->nbr;
	current = stack;
	while (current != NULL)
	{
		if (current->nbr > max_nbr)
			max_nbr = current->nbr;
		current = current->next;
	}
	return (max_nbr);
}

int	find_stack_min(t_stack *stack)
{
	int		min_nbr;
	t_stack	*current;

	if (stack == NULL)
		return (-1);
	min_nbr = stack->nbr;
	current = stack;
	while (current != NULL)
	{
		if (current->nbr < min_nbr)
			min_nbr = current->nbr;
		current = current->next;
	}
	return (min_nbr);
}

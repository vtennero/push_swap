/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:29:51 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/19 16:17:51 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_new_node(int nbr)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*append_to_list(t_stack **head, int nbr)
{
	t_stack	*new_node;
	t_stack	*current;

	current = NULL;
	new_node = create_new_node(nbr);
	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	return (*head);
}

void	free_stack(t_stack *start)
{
	t_stack	*current;
	t_stack	*temp;

	current = start;
	while (current->prev != NULL && current->prev != start)
	{
		current = current->prev;
	}
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:32:08 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/11 10:50:08 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// This function returns the last element of the stack.
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// This function returns the size of the stack.
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

//

t_stack *create_new_node(long nbr, int index)
{
    t_stack *new_node;
	
	new_node = ft_calloc(1, sizeof(t_stack));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->nbr = nbr;
    new_node->index = index;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append_to_list(t_stack **head, long nbr)
{
    t_stack *new_node;
	t_stack *current;

	current = NULL;
	new_node = create_new_node(nbr, ft_lstsize(*head));
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
}

void	free_stack(t_stack *head)
{
    t_stack *current;
	
	current = head;
    while (current != NULL)
	{
        t_stack *temp = current;
        current = current->next;
        free(temp);
    }
}

int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int find_stack_max(t_stack *stack)
{
    long    max_nbr;
    t_stack *current;

    if (stack == NULL)
        return -1; // Or some other error value, as the stack is empty

    max_nbr = stack->nbr;
    current = stack;
    while (current != NULL) {
        if (current->nbr > max_nbr) {
            max_nbr = current->nbr;
        }
        current = current->next;
    }

    return max_nbr;
}

int find_stack_min(t_stack *stack)
{
    long min_nbr;
    t_stack *current;

    if (stack == NULL)
        return -1; // Or some other error value, as the stack is empty

    min_nbr = stack->nbr;
    current = stack;
    while (current != NULL) {
        if (current->nbr > min_nbr) {
            min_nbr = current->nbr;
        }
        current = current->next;
    }

    return min_nbr;
}

void stack_reallocate_index(t_stack *stack)
{
    long index;
    t_stack *current;
    
    
    current = stack;
    index = 0;
    while (current != NULL)
    {
        current->index = index;
        index++;
        current = current->next;
    }
}
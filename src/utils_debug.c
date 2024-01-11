/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/11 10:41:53 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_stack(t_stack *head, char c)
{
    t_stack *current;
	
	current = head;
	ft_printf("Stack %c\n", c);
    while (current != NULL)
	{
        ft_printf("%d index %d\n", current->nbr, current->index);
        current = current->next;
    }
}
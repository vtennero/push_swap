/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:02:25 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/11 11:37:01 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	init_push(t_stack *a, t_stack *b)
// {
// 	op_pb(&a, &b);
// 	op_pb(&a, &b);
// 	// op_pb(&b, &a);
// 	// op_pb(&b, &a);
//     print_stack(a, 'a');
//     print_stack(b, 'b');
// }

void init_push(t_stack **a, t_stack **b)
{
    op_pb(a, b);
    op_pb(a, b);
}
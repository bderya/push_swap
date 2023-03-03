/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:44:33 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 03:02:11 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	rotate_a(t_list **stack_a, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_a) < 2)
		return ;
	tmp = *stack_a;
	*stack_a = listlast(*stack_a);
	(*stack_a)->next = tmp;
	(*stack_a) = tmp->next;
	tmp->next = NULL;
	if (!flag)
		write(1, "ra\n", 3);
}

/*
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/
void	rotate_b(t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_b) < 2)
		return ;
	tmp = *stack_b;
	*stack_b = listlast(*stack_b);
	(*stack_b)->next = tmp;
	(*stack_b) = tmp->next;
	tmp->next = NULL;
	if (!flag)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b, int flag)
{
	if (listsize(*stack_a) < 2 || listsize(*stack_b) < 2)
		return ;
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	if (!flag)
		write(1, "rr\n", 3);
}

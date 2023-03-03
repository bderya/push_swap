/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:44:15 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 01:49:06 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	swap_a(t_list **stack_a, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_a) < 2)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (!flag)
		write(1, "sa\n", 3);
}

/*
Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements
*/
void	swap_b(t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_b) < 2)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (!flag)
		write(1, "sa\n", 3);
}

void	swap_ab(t_list **stack_a, t_list **stack_b, int flag)
{
	if (listsize(*stack_a) < 2 || listsize(*stack_b) < 2)
		return ;
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	if (!flag)
		write(1, "ss\n", 3);
}

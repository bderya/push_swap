/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:20:23 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 01:20:25 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	from:
	STACK A			STACK B
	STACK A->next	STACK B->next
	...				...

	to:
	STACK B       	STACK B->next     
	STACK A			...
	...
*/
void	push_to_a(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_b) == 0)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	listadd_front(stack_a, tmp);
	if (!flag)
		write(1, "pa\n", 3);
}

/*
		from:
		STACK B			STACK A
		STACK B->next	STACK A->next
		...				...

		to:
		STACK A       	STACK A->next     
		STACK B			...
		...
	*/
void	push_to_b(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (listsize(*stack_a) == 0)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	listadd_front(stack_b, tmp);
	if (!flag)
		write(1, "pb\n", 3);
}

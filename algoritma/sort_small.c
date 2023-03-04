/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:43:36 by bderya            #+#    #+#             */
/*   Updated: 2023/03/04 22:29:57 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_numbers_sorthing(t_list **stack_a, t_list **stack_b, int min)
{
	int	index;

	index = find_index(*stack_a, min);
	while (index > 0 && is_sorted(stack_a) != true)
	{
		if (listsize(*stack_b) > 1 && (*stack_b)->nbr < (*stack_b)->next->nbr)
			rotate_ab(stack_a, stack_b, 0);
		else
			rotate_a(stack_a, 0);
		if (listsize(*stack_b) > 1 && (*stack_b)->nbr < (*stack_b)->next->nbr)
			swap_b(stack_b, 0);
		index--;
	}
	if (!(is_sorted(stack_a)))
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
	while (listsize(*stack_b) != 0)
		push_to_a(stack_a, stack_b, 0);
}

void	is_not_small_shorted(t_list **stack_a, int min)
{
	t_list	*temp;
	int		a;
	int		last;

	temp = listlast(*stack_a);
	a = find_index((*stack_a), min);
	last = find_index((*stack_a), temp->nbr);
	if (last == a)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			swap_a(stack_a, 0);
		reverse_rotate_a(stack_a, 0);
	}
	else
	{
		while (a > 0)
		{
			rotate_a(stack_a, 0);
			a--;
		}
	}
}

void	find_small_move(t_list **stack)
{
	int	min;

	min = find_min(stack);
	if (!(is_sorted(stack)))
		is_not_small_shorted(stack, min);
}

void	sort_small_2(t_list **stack_a, t_list **stack_b, int min, int index)
{
	while (listsize(*stack_a) > 3 && is_sorted(stack_a) != true)
	{
		min = find_min(stack_a);
		index = find_index(*stack_a, min);
		if (index <= listsize(*stack_a) / 2)
			while ((*stack_a)->nbr != min && is_sorted(stack_a) != true)
				rotate_a(stack_a, 0);
		else
			while ((*stack_a)->nbr != min && is_sorted(stack_a) != true)
				reverse_rotate_a(stack_a, 0);
		push_to_b(stack_a, stack_b, 0);
	}
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	t_list	*decider;
	int		min;
	int		index;

	decider = copy_list(*stack_a);
	sort_list(decider, 0, 0);
	min = decider->nbr;
	index = 0;
	if (listsize(*stack_a) <= 5 && listsize(*stack_a) != 3 && \
		is_sorted(stack_a) != true)
		sort_small_2(stack_a, stack_b, min, index);
	else
		find_small_move(stack_a);
	min = find_min(stack_a);
	small_numbers_sorthing(stack_a, stack_b, min);
}

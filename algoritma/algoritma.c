/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritma.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:13:42 by bderya            #+#    #+#             */
/*   Updated: 2023/03/04 18:40:53 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Three number in stack*/
void	small_numbers(t_list **stack, t_data *my_data)
{
	int	index;

	index = find_index(*stack, my_data->min);
	while (index > 0)
	{
		rotate_a(stack, 0);
		index--;
	}
	if (!(is_sorted(stack)))
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
}

void	first_sort(t_list **stack_a, t_list **stack_b, t_data data)
{
	while (listsize(*stack_a) > 3)
	{
		if ((*stack_a)->nbr != data.max && (*stack_a)->nbr != data.min && \
			(*stack_a)->nbr != data.median)
		{
			if ((*stack_a)->nbr > data.median)
			{
				push_to_b(stack_a, stack_b, 0);
				rotate_b(stack_b, 0);
			}
			else
				push_to_b(stack_a, stack_b, 0);
		}
		else
			rotate_a(stack_a, 0);
	}
}

void	second_sort(t_list **stack_a, t_list **stack_b, t_data *data,
	int num_stack_b)
{
	while (num_stack_b > 0)
	{
		min_cost_cal(stack_a, stack_b, data);
		if (data->cost_a[0] != -1 && data->cost_b[0] != -1)
			min_rotate(stack_a, stack_b, data);
		else if (data->cost_a[1] != -1 && data->cost_b[1] != -1)
			min_reverse_rotate(stack_a, stack_b, data);
		else if (data->cost_a[0] != -1 && data->cost_b[1] != -1)
			min_rotate_a_reverse_rotate_b(stack_a, stack_b, data);
		else if (data->cost_a[1] != -1 && data->cost_b[0] != -1)
			min_reverse_rotate_a_rotate_b(stack_a, stack_b, data);
		push_to_a(stack_a, stack_b, 0);
		num_stack_b--;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*decider;
	t_data	data;
	int		num_stack_b;

	decider = copy_list(*stack_a);
	sort_list(decider, 0, 0);
	data.max = find_max(decider);
	data.min = decider->nbr;
	find_median(decider, &data);
	first_sort(stack_a, stack_b, data);
	small_numbers(stack_a, &data);
	num_stack_b = listsize(*stack_b);
	second_sort(stack_a, stack_b, &data, num_stack_b);
	if (!(is_sorted(stack_a)))
		is_not_shorted(stack_a, &data);
	listclear(stack_a);
	listclear(stack_b);
	listclear(&decider);
}

bool	algoritma(t_list **stack_a, t_list **stack_b)
{
	if (listsize(*stack_a) > 5)
		big_sort(stack_a, stack_b);
	else
		sort_small(stack_a, stack_b);
	return (true);
}

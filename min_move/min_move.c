/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:24:49 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 01:20:51 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_rotate(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->cost_a[0] > 0 && data->cost_b[0])
	{
		rotate_ab(stack_a, stack_b, 0);
		data->cost_a[0]--;
		data->cost_b[0]--;
	}
	while (data->cost_a[0] > 0)
	{
		rotate_a(stack_a, 0);
		data->cost_a[0]--;
	}
	while (data->cost_b[0] > 0)
	{
		rotate_b(stack_b, 0);
		data->cost_b[0]--;
	}
}

void	min_reverse_rotate(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->cost_a[1] > 0 && data->cost_b[1] && listsize(*stack_b) > 2)
	{
		reverse_rotate_ab(stack_a, stack_b, 0);
		data->cost_a[1]--;
		data->cost_b[1]--;
	}
	while (data->cost_a[1] > 0)
	{
		reverse_rotate_a(stack_a, 0);
		data->cost_a[1]--;
	}
	while (data->cost_b[1] > 0)
	{
		reverse_rotate_b(stack_b, 0);
		data->cost_b[1]--;
	}
}

void	min_rotate_a_reverse_rotate_b(t_list **stack_a, t_list **stack_b,
	t_data *data)
{
	while (data->cost_a[0] > 0)
	{
		rotate_a(stack_a, 0);
		data->cost_a[0]--;
	}
	while (data->cost_b[1] > 0)
	{
		reverse_rotate_b(stack_b, 0);
		data->cost_b[1]--;
	}
}

void	min_reverse_rotate_a_rotate_b(t_list **stack_a, t_list **stack_b,
	t_data *data)
{
	while (data->cost_a[1] > 0)
	{
		reverse_rotate_a(stack_a, 0);
		data->cost_a[1]--;
	}
	while (data->cost_b[0] > 0)
	{
		rotate_b(stack_b, 0);
		data->cost_b[0]--;
	}
}

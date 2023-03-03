/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_move_cal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:40:26 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 00:17:58 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_cal(t_data *my_data)
{
	my_data->min_cost = my_max(my_data->rot_a, my_data->rot_b);
	my_data->cost_a[0] = my_data->rot_a;
	my_data->cost_a[1] = -1;
	my_data->cost_b[0] = my_data->rot_b;
	my_data->cost_b[1] = -1;
}

void	rev_rotate_cal(t_data *my_data)
{
	my_data->min_cost = my_max(my_data->rev_rot_a, my_data->rev_rot_b);
	my_data->cost_a[0] = -1;
	my_data->cost_a[1] = my_data->rev_rot_a;
	my_data->cost_b[0] = -1;
	my_data->cost_b[1] = my_data->rev_rot_b;
}

void	rot_a_ret_rot_b_cal(t_data *my_data)
{
	my_data->min_cost = (my_data->rot_a + my_data->rev_rot_b);
	my_data->cost_a[0] = my_data->rot_a;
	my_data->cost_a[1] = -1;
	my_data->cost_b[0] = -1;
	my_data->cost_b[1] = my_data->rev_rot_b;
}

void	rev_rot_a_rot_b(t_data *my_data)
{
	my_data->min_cost = (my_data->rev_rot_a + my_data->rot_b);
	my_data->cost_a[0] = -1;
	my_data->cost_a[1] = my_data->rev_rot_a;
	my_data->cost_b[0] = my_data->rot_b;
	my_data->cost_b[1] = -1;
}

void	min_cost_cal(t_list **stack_a, t_list **stack_b, t_data *my_data)
{
	t_list	*temp_b;
	int		i;

	temp_b = *stack_b;
	my_data->min_cost = INT_MAX;
	i = 0;
	while (temp_b)
	{
		my_data->rot_a = insert_pos(stack_a, temp_b->nbr);
		my_data->rev_rot_a = listsize(*stack_a) - my_data->rot_a;
		my_data->rot_b = i;
		my_data->rev_rot_b = listsize(*stack_b) - i;
		if (my_max(my_data->rot_a, my_data->rot_b) < my_data->min_cost)
			rotate_cal(my_data);
		if (my_max(my_data->rev_rot_a, my_data->rev_rot_b) < my_data->min_cost)
			rev_rotate_cal(my_data);
		if ((my_data->rot_a + my_data->rev_rot_b) < my_data->min_cost)
			rot_a_ret_rot_b_cal(my_data);
		if ((my_data->rev_rot_a + my_data->rot_b) < my_data->min_cost)
			rev_rot_a_rot_b(my_data);
		temp_b = temp_b->next;
		i++;
	}
}

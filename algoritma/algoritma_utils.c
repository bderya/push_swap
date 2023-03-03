/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritma_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:12:29 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 02:52:06 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_list(t_list *stack, int swapped, long int temp)
{
	t_list		*first_point;
	t_list		*last_ptr;

	last_ptr = NULL;
	if (stack == NULL)
		return ;
	while (1)
	{
		swapped = 0;
		first_point = stack;
		while (first_point->next != last_ptr)
		{
			if (first_point->nbr > first_point->next->nbr)
			{
				temp = first_point->nbr;
				first_point->nbr = first_point->next->nbr;
				first_point->next->nbr = temp;
				swapped = 1;
			}
			first_point = first_point->next;
		}
		if (!swapped)
			break ;
		last_ptr = first_point;
	}
}

int	find_index(t_list *head, int element)
{
	int		index;
	t_list	*current;

	index = 0;
	current = head;
	while (current != NULL)
	{
		if (current->nbr == element)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

void	is_not_shorted(t_list **stack_a, t_data *data)
{
	int		a;

	a = find_index((*stack_a), data->min);
	while (a > 0)
	{
		rotate_a(stack_a, 0);
		a--;
	}
}

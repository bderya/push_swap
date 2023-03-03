/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:53:07 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 02:11:11 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	my_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	my_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_max(t_list *head)
{
	int		max;
	t_list	*current;

	max = head->nbr;
	current = head->next;
	while (current != NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

void	find_median(t_list *decider, t_data *data)
{
	int	i;
	int	length;

	length = listsize(decider) / 2;
	i = 0;
	while (i < length)
	{
		if (i == length -1)
			data->median = decider->nbr;
		decider = decider->next;
		i++;
	}
}

bool	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (false);
		temp = temp->next;
	}
	return (true);
}

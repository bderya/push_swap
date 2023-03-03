/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:10:25 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 02:17:36 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	insert_pos(t_list **stack, long int target)
{
	t_list	*temp;
	int		index;

	index = 0;
	temp = *stack;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->nbr < target && temp->next->nbr > target)
			return (index + 1);
		index++;
		temp = temp->next;
	}
	index = 0;
	return (index);
}

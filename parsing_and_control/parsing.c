/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:56:24 by bderya            #+#    #+#             */
/*   Updated: 2023/03/04 22:29:46 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*copy_list(t_list *head)
{
	t_list	*new_head;
	t_list	*curr;
	t_list	*prev;
	t_list	*new_node;

	if (head == NULL)
		return (NULL);
	new_head = (t_list *)malloc(sizeof(t_list));
	new_head->nbr = head->nbr;
	new_head->next = NULL;
	curr = head->next;
	prev = new_head;
	while (curr != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		new_node->nbr = curr->nbr;
		new_node->next = NULL;
		prev->next = new_node;
		prev = new_node;
		curr = curr->next;
	}
	return (new_head);
}

void	add_number(t_list **stack, int data)
{
	t_list	*temp;
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->nbr = data;
	new_node->next = NULL;
	if ((*stack) == NULL)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

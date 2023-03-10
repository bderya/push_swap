/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:05:44 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 03:43:16 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (check_input(argc, argv, &stack_a) != true)
	{
		write(2, "Error\n", 6);
		listclear(&stack_a);
	}
	else if (algoritma(&stack_a, &stack_b) == true)
		return (0);
	return (0);
}

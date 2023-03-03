/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:56:00 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 01:38:10 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_space(char *arguments, int i, bool space)
{
	i = 0;
	space = false;
	while (arguments[i] != '\0')
	{
		while (ft_isspace(arguments[i]) == true)
		{
			space = true;
			i++;
		}
		if (arguments[i] == ' ')
			return (false);
		if (((arguments[i] == '-' || arguments[i] == '+') && space == true) \
			|| (arguments[i] == '-' || arguments[i] == '+'))
		{
			if (space == true)
				space = false;
			i++;
		}
		space = false;
		if (ft_isdigit(arguments[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_argument_value(char *arguments)
{
	if (word_counter(arguments) == true)
	{
		if (check_space(arguments, 0, false) != true)
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	check_duplicate_2(t_list **stack)
{
	t_list	*current;
	t_list	*runner;

	if (stack == NULL)
		return (true);
	current = (*stack);
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->nbr == runner->nbr)
			{
				return (false);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (true);
}

bool	check_duplicate(t_list **stack, int argc, char **argv, int i)
{
	long int	number;
	int			cut;
	char		**token;

	while (i < argc)
	{
		cut = 0;
		token = ft_split(argv[i], ' ');
		while (token[cut] != NULL)
		{
			number = ft_atoi(token[cut++]);
			add_number(stack, number);
		}
		i++;
	}
	if (check_duplicate_2(stack) != true)
		return (false);
	return (true);
}

bool	check_input(int argc, char **argv, t_list **stack)
{
	int	i;
	int	number;
	int	cut;

	i = 1;
	cut = 0;
	number = 0;
	if (argc < 2)
		error_input();
	while (i < argc)
		if (check_argument_value(argv[i++]) == false)
			return (false);
	i = 1;
	if (check_duplicate(stack, argc, argv, i) == false)
	{
		//free_struct();
		return (false);
	}
	return (true);
}

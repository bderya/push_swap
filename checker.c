/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:44:08 by bderya            #+#    #+#             */
/*   Updated: 2023/03/04 22:25:04 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stringncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

bool	error_ch(void)
{
	write(2, "Error\n", 6);
	return (false);
}

bool	check_command(t_list **stack_a, t_list **stack_b, char *str)
{
	if (stringncmp(str, "sa", 2) == 0 && str[2] == '\0')
		swap_a(stack_a, 1);
	else if (stringncmp(str, "sb", 2) == 0 && str[2] == '\0')
		swap_b(stack_b, 1);
	else if (stringncmp(str, "ss", 2) == 0 && str[2] == '\0')
		swap_ab(stack_a, stack_a, 0);
	else if (stringncmp(str, "pa", 2) == 0 && str[2] == '\0')
		push_to_a(stack_a, stack_b, 1);
	else if (stringncmp(str, "pb", 2) == 0 && str[2] == '\0')
		push_to_b(stack_a, stack_b, 1);
	else if (stringncmp(str, "ra", 2) == 0 && str[2] == '\0')
		rotate_a(stack_a, 1);
	else if (stringncmp(str, "rb", 2) == 0 && str[2] == '\0')
		rotate_b(stack_b, 1);
	else if (stringncmp(str, "rr", 2) == 0 && str[2] == '\0')
		rotate_ab(stack_a, stack_b, 1);
	else if (stringncmp(str, "rra", 3) == 0 && str[3] == '\0')
		reverse_rotate_a(stack_a, 1);
	else if (stringncmp(str, "rrb", 3) == 0 && str[3] == '\0')
		reverse_rotate_b(stack_b, 1);
	else if (stringncmp(str, "rrr", 3) == 0 && str[3] == '\0')
		reverse_rotate_ab(stack_a, stack_b, 1);
	else
		return (error_ch());
	return (true);
}

void	command_order(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = modif_get(0);
	while (line)
	{	
		if (line[0] == '\n' || line[0] == '\0')
			break ;
		if (check_command(stack_a, stack_b, line) == true)
		{
			free(line);
			line = modif_get(0);
		}
		else
		{
			listclear(stack_a);
			listclear(stack_b);
			exit (0);
		}
	}
}

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
		return (1);
	}
	if (!(is_sorted(&stack_a)))
		command_order(&stack_a, &stack_b);
	else
		return (0);
	if (!is_sorted(&stack_a) || listsize(stack_b) > 0)
		write(2, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	listclear(&stack_a);
	listclear(&stack_b);
	return (0);
}

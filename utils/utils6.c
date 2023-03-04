/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:37:09 by bderya            #+#    #+#             */
/*   Updated: 2023/03/04 22:25:09 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	listclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = temp;
	}
}

int	find_min(t_list **stack)
{
	int		min;
	t_list	*temp;

	temp = (*stack);
	min = temp->nbr;
	while (temp != NULL)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	return (min);
}

char	*modif_get2(char *buffer, char string, int fd, int file)
{
	int	i;

	i = 0;
	while (file > 0 && i != 5)
	{
		buffer[i] = string;
		if (string == '\n')
			break ;
		file = read(fd, &string, 1);
		i++;
	}
	if (!buffer[i - 1] && file < 0 && i == 6)
	{
		free(buffer);
		return (NULL);
	}
	while (i < 5)
		buffer[i++] = '\0';
	return (buffer);
}

char	*modif_get(int fd)
{
	char	string;
	char	*buffer;
	int		file;

	if (read(fd, 0, 0) == -1 || fd < 0)
		return (0);
	buffer = (char *)malloc(6 * sizeof(char));
	if (!buffer)
		return (NULL);
	file = read(fd, &string, 1);
	buffer = modif_get2(buffer, string, fd, file);
	return (buffer);
}

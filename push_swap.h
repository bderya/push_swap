/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bderya <bderya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:21:27 by bderya            #+#    #+#             */
/*   Updated: 2023/03/03 03:04:01 by bderya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	long int		nbr;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	long int	max;
	long int	min;
	long int	median;
	int			min_cost;
	int			rot_a;
	int			rot_b;
	int			rev_rot_a;
	int			rev_rot_b;
	int			cost_a[2];
	int			cost_b[2];
}	t_data;

/* Algo*/
bool	algoritma(t_list **stack_a, t_list **stack_b);

/* Sort list */
void	sort_list(t_list *stack, int swapped, long int temp);
/* List control */
bool	is_sorted(t_list **stack);
/* Find number and index for sort */
int		my_max(int a, int b);
int		my_min(int a, int b);
int		find_max(t_list *head);
void	find_median(t_list *decider, t_data *data);
int		find_index(t_list *head, int element);
int		find_index(t_list *head, int element);

/** Error hand **/
int		ft_error(void);
void	error_input(void);

/** SORT **/
void	big_sort(t_list **stack_a, t_list **stack_b);

/** Utils for checking arg and parsing **/
/*Split*/
char	**ft_split(char const *s, char c);

/** Controller for check_argument_value **/
bool	word_counter(char *str);
bool	check_space(char *arguments, int i, bool space);
bool	ft_isdigit(int c);
bool	ft_isspace(char ch);
int		ft_atoi(const char *str);

/** Checker for argument**/
bool	check_input(int argc, char **argv, t_list **stack);
bool	check_duplicate(t_list **stack, int argc, char **argv, int i);
bool	check_duplicate_2(t_list **stack);
bool	check_argument_value(char *arguments);

/** Parsing function **/
void	add_number(t_list **stack, int data);

 /** Utils for list**/
t_list	*copy_list(t_list *head);
t_list	*listlast(t_list *lst);
int		listsize(t_list *lst);
void	listadd_back(t_list **lst, t_list *new);
void	listadd_front(t_list **lst, t_list *new);

/** MINIMUM MOVE FUNCTIONS **/
/* Minimum move cal*/
int		insert_pos(t_list **stack, long int target);
void	min_cost_cal(t_list **stack_a, t_list **stack_b, t_data *my_data);

/* Minimum move */
void	min_rotate(t_list **stack_a, t_list **stack_b, t_data *data);
void	min_reverse_rotate(t_list **stack_a, t_list **stack_b, t_data *data);
void	min_rotate_a_reverse_rotate_b(t_list **stack_a, t_list **stack_b,
			t_data *data);
void	min_reverse_rotate_a_rotate_b(t_list **stack_a, t_list **stack_b,
			t_data *data);

/** Move command **/
/* SWAP && sa - sb - ss */
void	swap_a(t_list **stack_a, int flag);
void	swap_b(t_list **stack_b, int flag);
void	swap_ab(t_list **stack_a, t_list **stack_b, int flag);

/* PUSH && pa - pb */
void	push_to_a(t_list **stack_a, t_list **stack_b, int flag);
void	push_to_b(t_list **stack_a, t_list **stack_b, int flag);

/* ROTATE && ra - rb - rr */
void	rotate_a(t_list **stack_a, int flag);
void	rotate_b(t_list **stack_b, int flag);
void	rotate_ab(t_list **stack_a, t_list **stack_b, int flag);

/* REVERSE ROTATE && rra - rrb - rrr */
void	reverse_rotate_a(t_list **stack_a, int flag);
void	reverse_rotate_b(t_list **stack_b, int flag);
void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b, int flag);

#endif
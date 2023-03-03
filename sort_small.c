#include "push_swap.h"

int small_median(t_list *decider)
{
	int i;
	int length;
	int median;

	length = listsize(decider) / 2;
	i = 0;
	while(i  < length)
	{
		if (i == length -1)
			median = decider->nbr;
		decider = decider->next;
		i++; 
	}
	return (median)
}

void sort_small(t_list **stack_a, t_list **stack_b)
{
    t_list	*decider;
	int		median;
	decider = copy_list(*stack_a);
	sort_list(decider, 0, 0);
	median = small_median(decider);
	while (listsize(*stack_a) > 4)
	{
		if ((*stack_a)->nbr != median && (*stack_a)->nbr >= median)
		{
			if ((*stack_a)->nbr > median)
			{
				push_to_b(stack_a, stack_b, 0);
				rotate_b(stack_b, 0);
			}
			else
				push_to_b(stack_a, stack_b, 0);
		}
		else
			rotate_a(stack_a, 0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:26 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/15 13:44:12 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_take_pivot(list **stack)
{
	int pivot;
	list *curent;
	curent = (*stack);
	while(curent->next != NULL)
	{
		curent = curent->next;
	}
	pivot = curent->value;
	return (pivot);
}

int ft_checktri(list **stack_a)
{
	list *curent;

	curent = (*stack_a);
	while(curent->next != NULL)
	{
		if(curent->value > curent->next->value)
		{
			return (0);
		}
		curent = curent->next;
	}
	return (0);
}

void ft_quicksort(list **stack_a, list **stack_b)
{
	int pivot;
	list *curent;
	pivot = ft_take_pivot(stack_a);
	curent = (*stack_a);
	while(curent->next->value != pivot) //pivot haut pile a, +petit pile b, +grand dessous pivot
	{
		if (curent->value > pivot)
		{
			ra(stack_a);
		}
		if (curent->value > pivot)
		{
			pb(stack_a, stack_b);
		}
		curent = curent->next;
	}
	curent = (*stack_b);
	while(curent->next->value != pivot)
	{
		if (curent->value < pivot)
		{
			rb(stack_b);
		}
		if (curent->value > pivot)
		{
			pa(stack_a, stack_b);
		}
		curent = curent->next;
	}
	while(curent->next != NULL) //tous dans stack_a
	{
		pa(stack_a, stack_b);
	}
	if(ft_checktri(stack_a) == 0)
	{
		ft_quicksort(stack_a, stack_b);
	}
	/*if((*stack_a)->value > (*stack_a)->next->value)
		{
			sa((*stack_a));
		}
		if((*stack_b)->value < (*stack_b)->next->value)
		{
			sb((*stack_b));
		}*/
}
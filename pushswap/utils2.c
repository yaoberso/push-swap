/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:10:40 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:25:39 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_max(t_list **stack)
{
	t_list	*curent;
	int		max;

	curent = (*stack);
	max = curent->value;
	while (curent->next != NULL)
	{
		if (curent->next->value > max)
		{
			max = curent->next->value;
		}
		curent = curent->next;
	}
	return (max);
}

int	find_min(t_list **stack)
{
	t_list	*curent;
	int		min;

	curent = (*stack);
	min = curent->value;
	while (curent->next != NULL)
	{
		if (curent->next->value < min)
		{
			min = curent->next->value;
		}
		curent = curent->next;
	}
	return (min);
}

int	find_max_position(t_list *stack)
{
	int		max_pos;
	int		pos;
	int		max_value;
	t_list	*current;

	max_pos = 0;
	pos = 0;
	max_value = stack->value;
	current = stack;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

int	find_min_position(t_list *stack)
{
	int		min_pos;
	int		pos;
	int		min_value;
	t_list	*current;

	min_pos = 0;
	pos = 0;
	min_value = stack->value;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	stack_size(t_list *stack)
{
	int		size;
	t_list	*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

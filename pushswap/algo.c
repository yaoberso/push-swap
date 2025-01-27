/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:26 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:32 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_trois(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa((*stack_a));
	else if (a > b && b > c)
	{
		sa((*stack_a));
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa((*stack_a));
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	ft_cinq(t_list **stack_a, t_list **stack_b)
{
	ft_cinq_move_min(stack_a, stack_b);
	ft_cinq_move_max(stack_a, stack_b);
	ft_trois(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
}

void	ft_more5(t_list **stack_a, t_list **stack_b, int nb_chunk)
{
	int	**chunks;

	chunks = ft_plusde5_set_chunks(stack_a, nb_chunk);
	if (!chunks)
		return ;
	ft_plusde5_chunk_sort(stack_a, stack_b, chunks, nb_chunk);
	ft_plusde5_stack_b_sort(stack_a, stack_b);
	ft_plusde5_free_chunks(chunks, nb_chunk);
}

void	ft_algo(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 3)
	{
		ft_trois(stack_a);
	}
	if (size == 5)
	{
		ft_cinq(stack_a, stack_b);
	}
	if (size <= 100 && size > 5)
	{
		ft_more5(stack_a, stack_b, 5);
	}
	else if (size > 100)
	{
		ft_more5(stack_a, stack_b, 11);
	}
}

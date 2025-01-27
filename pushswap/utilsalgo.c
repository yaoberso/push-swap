/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsalgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:10:56 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:19:27 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_cinq_move_min(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	size = stack_size(*stack_a);
	min_pos = find_min_position(*stack_a);
	if (min_pos <= size / 2)
	{
		while ((*stack_a)->value != find_min(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != find_min(stack_a))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	ft_cinq_move_max(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	size;

	size = stack_size(*stack_a);
	max_pos = find_max_position(*stack_a);
	if (max_pos <= size / 2)
	{
		while ((*stack_a)->value != find_max(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != find_max(stack_a))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

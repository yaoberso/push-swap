/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:10:48 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:21:47 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	**set_chunk(int min, int max, int nb_chunk)
{
	int	**chunks;
	int	interval;
	int	i;

	i = 0;
	chunks = ft_set_chunk_malloc(nb_chunk);
	if (!chunks)
		return (NULL);
	interval = (max - min + 1) / nb_chunk;
	while (i < nb_chunk)
	{
		chunks[i] = ft_set_chunk_allocate_chunk();
		if (!chunks[i])
		{
			ft_set_chunk_free(chunks, i);
			return (NULL);
		}
		ft_set_chunk_fill_chunk(chunks[i], &min, interval, i, nb_chunk, max);
		i++;
	}
	return (chunks);
}

int	find_position(t_list **stack_a, int value)
{
	t_list	*current;
	int		pos;

	current = *stack_a;
	pos = 0;
	while (current != NULL)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	free_chunk(int **chunk, int size)
{
	int	i;

	i = 0;
	if (chunk)
	{
		while (i < size)
		{
			free(chunk[i]);
			i++;
		}
		free(chunk);
	}
}

void	ft_plusde5_stack_b_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_value;
	int	position;

	while (*stack_b)
	{
		max_value = find_max(stack_b);
		position = find_position(stack_b, max_value);
		if (position <= stack_size(*stack_b) / 2)
		{
			while (position-- > 0)
				rb(stack_b);
		}
		else
		{
			position = stack_size(*stack_b) - position;
			while (position-- > 0)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	ft_plusde5_free_chunks(int **chunks, int nb_chunk)
{
	int	chunk_index;

	chunk_index = 0;
	while (chunk_index < nb_chunk)
	{
		free(chunks[chunk_index]);
		chunk_index++;
	}
	free(chunks);
}

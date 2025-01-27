/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:55 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:18:51 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi_utils(char *str, int r, int i)
{
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		if (r > INT_MAX || r < INT_MIN)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (r);
}

long int	ft_atoi(char *str)
{
	int long	r;
	int			s;
	int			i;
	int			cmpt;

	r = 0;
	s = 1;
	i = 0;
	cmpt = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (cmpt > 0)
		{
			printf("Error\n");
			exit(1);
		}
		if (str[i] == '-')
			s = -1;
		i++;
		cmpt++;
	}
	return (ft_atoi_utils(str, r, i) * s);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	**ft_plusde5_set_chunks(t_list **stack_a, int nb_chunk)
{
	int	min;
	int	max;
	int	**chunks;

	min = find_min(stack_a);
	max = find_max(stack_a);
	chunks = set_chunk(min, max, nb_chunk);
	if (!chunks)
		return (NULL);
	return (chunks);
}

void	ft_plusde5_chunk_sort(t_list **stack_a, t_list **stack_b, int **chunks,
		int nb_chunk)
{
	int	chunk_index;
	int	size_a;
	int	value;

	chunk_index = 0;
	while (chunk_index < nb_chunk)
	{
		size_a = stack_size(*stack_a);
		while (size_a-- > 0)
		{
			value = (*stack_a)->value;
			if (value >= chunks[chunk_index][0]
				&& value <= chunks[chunk_index][1])
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		chunk_index++;
	}
}

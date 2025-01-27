/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilschunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:11:07 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:13 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	**ft_set_chunk_malloc(int nb_chunk)
{
	int	**chunks;

	chunks = malloc(sizeof(int *) * nb_chunk);
	if (!chunks)
		return (NULL);
	return (chunks);
}

int	*ft_set_chunk_allocate_chunk(void)
{
	int	*chunk;

	chunk = malloc(sizeof(int) * 2);
	if (!chunk)
		return (NULL);
	return (chunk);
}

void	ft_set_chunk_fill_chunk(int *chunk, int *min, int interval, int i,
		int nb_chunk, int max)
{
	chunk[0] = *min;
	if (i == nb_chunk - 1)
		chunk[1] = max;
	else
		chunk[1] = *min + interval;
	*min = *min + interval;
}

void	ft_set_chunk_free(int **chunks, int i)
{
	while (i > 0)
	{
		i--;
		free(chunks[i]);
	}
	free(chunks);
}

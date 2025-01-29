/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilschunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:11:07 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:46 by yann             ###   ########.fr       */
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

void	ft_set_chunk_fill_chunk(int *chunk, t_chunk_data *data, int i)
{
	chunk[0] = data->min;
    if (i == data->nb_chunk - 1)
        chunk[1] = data->max;
    else
        chunk[1] = data->min + data->interval;
    data->min += data->interval;
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

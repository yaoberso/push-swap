/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:10:14 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:52 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	checkdbl(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	checkifalph(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] <= '9' && argv[i][j] >= '0') && argv[i][j] != '-')
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_error(char **argv)
{
	checkdbl(argv);
	checkifalph(argv);
}

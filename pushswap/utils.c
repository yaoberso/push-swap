/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:55 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/14 13:54:45 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long int ft_atoi(char *str)
{
	int long r;
	int s;
	int i;
	int cmpt;

	r = 0;
	s = 1;
	i = 0;
	cmpt = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while(str[i] == '+' || str[i] == '-')
	{
		if(cmpt > 0)
		{
			printf("Error\n");
			exit(1);
		}
		if (str[i] == '-')
			s = -1;
		i++;
		cmpt++;
	}
	while(str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		if (r > INT_MAX || r < INT_MIN)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (r * s);
}



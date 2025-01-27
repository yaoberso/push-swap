/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:55 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:55 by yann             ###   ########.fr       */
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

void print_stack(list *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

void free_stack(list *stack)
{
	while (stack)
    {
        list *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

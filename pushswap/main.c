/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:00 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Error\n");
		exit(0);
	}
	int i;
	list *head = NULL;
	list *current = NULL;

	i = 2;
	head = malloc(sizeof(list));
	head->value = ft_atoi(argv[1]);
	head->next = NULL;
	current = head;
	while(i < argc)
	{
		current->next = malloc(sizeof(list));
		current = current->next;
		current->value = ft_atoi(argv[i]);
		current->next = NULL;
		i++;
	}
	i = 0;
	while(i < (argc - 1))
	{
		printf("%i", head->value);
		if (i != (argc - 2))
		{
			printf(" ");
		}
		head = head->next;
		i++;
	}
	return (0);
}
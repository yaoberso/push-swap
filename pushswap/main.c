/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/15 13:57:25 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void stockpile(int argc, char **argv, list **head)
{
	int i;
	list *current = NULL;

	i = 2;
	head = malloc(sizeof(list));
	(*head)->value = ft_atoi(argv[1]);
	(*head)->next = NULL;
	current = (*head);
	while(i < argc)
	{
		current->next = malloc(sizeof(list));
		current = current->next;
		current->value = ft_atoi(argv[i]);
		current->next = NULL;
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Error\n");
		exit(0);
	}
	list *curent;
	list *stack_a;
	list **stack_b = NULL;
	int i;

	stockpile(argc, argv, &stack_a);
	ft_quicksort(&stack_a, stack_b);
	i = 0;
	curent = stack_a;
	while(i < (argc - 1))
	{
		printf("%i", curent->value);
		if (i != (argc - 2))
		{
			printf(" ");
		}
		curent = curent->next;
		i++;
	}
	return (0);
}
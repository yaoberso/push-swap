/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/21 10:41:41 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void stockpile(int argc, char **argv, list **head)
{
	int i;
	list *current = NULL;

	i = 2;
	*head = malloc(sizeof(list));
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
	if (argc < 2)
    {
        printf("Error\n");
        return 1;
    }
    list *stack_a = NULL;
    list *stack_b = NULL;
	int size;
	
	size = argc - 1;
    stockpile(argc, argv, &stack_a);
    if (!stack_a)
    {
        printf("Error\n");
        return 1;
    }
    ft_quicksort(&stack_a, &stack_b, size);
    list *temp = stack_a;
    while (temp)
    {
        ft_printf("%d", temp->value);
        if (temp->next)
            ft_printf(" ");
        temp = temp->next;
    }
    ft_printf("\n");
    while (stack_a)
    {
        temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }
    return 0;
}
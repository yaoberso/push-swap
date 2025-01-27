/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/23 11:53:52 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void stockpile(int argc, char **argv, list **head)
{
    int i;
    list *current = NULL;

    i = 2;
    *head = malloc(sizeof(list));
    if (!(*head))
    {
        ft_printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    (*head)->value = ft_atoi(argv[1]);
    (*head)->next = NULL;
    current = (*head);

    while (i < argc)
    {
        current->next = malloc(sizeof(list));
        if (!current->next)
        {
            ft_printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
        current->value = ft_atoi(argv[i]);
        current->next = NULL;
        i++;
    }
}

int main(int argc, char **argv)
{
    list *stack_a = NULL;
    list *stack_b = NULL;
    int size;
    if (argc < 2)
        return (1);
    size = argc - 1;
    check_error(argv);
    stockpile(argc, argv, &stack_a);
    ft_algo(&stack_a, &stack_b, size);
    print_stack(stack_a);
    ft_printf("\n");
    free_stack(stack_a);

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:26 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:22 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_take_pivot(list **stack, int size)
{
    list *current = *stack;
    int values[size];
    int i = 0;
    while (current && i < size)
    {
        values[i++] = current->value;
        current = current->next;
    }
    int temp;
    for (int j = 0; j < size - 1; j++)
    {
        for (int k = j + 1; k < size; k++)
        {
            if (values[j] > values[k])
            {
                temp = values[j];
                values[j] = values[k];
                values[k] = temp;
            }
        }
    }
    return values[size / 2];
}

int ft_checktri(list **stack_a)
{
    list *current = *stack_a;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

void ft_quicksort(list **stack_a, list **stack_b, int size)
{
    if (size <= 1 || ft_checktri(stack_a) == 1)
        return;

    int pivot = ft_take_pivot(stack_a, size);
    ft_printf("pivot : %i", pivot);
    int count_b = 0;
    int i = 0;

    while (i++ < size)
    {
        if ((*stack_a)->value < pivot)
        {
            pb(stack_a, stack_b);
            count_b++;
        }
        else
            ra(stack_a);
    }
    ft_quicksort(stack_a, stack_b, size - count_b);
    ft_quicksort(stack_b, stack_a, count_b);
    while (count_b-- > 0)
    {
        if (*stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
            sb(*stack_b);
        pa(stack_a, stack_b);
    }
}


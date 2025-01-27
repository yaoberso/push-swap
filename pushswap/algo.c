/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:26 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/26 14:49:24 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_trois(list **stack_a)
{
    int a;
    int b;
    int c;
    
    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;
    if(a > b && b < c && a < c)
    {
        sa((*stack_a));
    }
    else if(a > b && b > c)
    {
        sa((*stack_a));
        rra(stack_a);
    }
    else if(a > b && b < c && a > c)
    {
        ra(stack_a);
    }
    else if(a < b && b > c && a < c)
    {
        sa((*stack_a));
        ra(stack_a);
    }
    else if(a < b && b > c && a > c)
    {
        rra(stack_a);
    }
}

void ft_cinq(list **stack_a, list **stack_b)
{
    int min_pos;
    int max_pos;
    int size;

    size = stack_size(*stack_a);
    min_pos = find_min_position(*stack_a);
    max_pos = find_max_position(*stack_a);

    if (min_pos <= size / 2)
    {
        while ((*stack_a)->value != find_min(stack_a))
            ra(stack_a);
    }
    else
    {
        while ((*stack_a)->value != find_min(stack_a))
            rra(stack_a);
    }
    pb(stack_a, stack_b);

    if (max_pos <= size / 2)
    {
        while ((*stack_a)->value != find_max(stack_a))
            ra(stack_a);
    }
    else
    {
        while ((*stack_a)->value != find_max(stack_a))
            rra(stack_a);
    }
    pb(stack_a, stack_b);

    ft_trois(stack_a);

    pa(stack_a, stack_b);
    ra(stack_a);
    pa(stack_a, stack_b);
}

void ft_centetmoin(list **stack_a, list **stack_b)
{
    int **chunk;
    list *current;
    int pos;
    int i;
    int size_a;
    int max;

    i = 0;
    pos = 0;
    chunk = set_chunk(find_min(stack_a), find_max(stack_a), 5);
    current = (*stack_a);
    size_a = stack_size(*stack_a);

    while (current != NULL)
    {
        if (current->value >= chunk[i][0] && current->value < chunk[i][1])
        {
            pos = find_position(stack_a, current->value);
            if (pos <= size_a / 2)
            {
                while (pos-- > 0)
                    ra(stack_a);
            }
            else
            {
                pos = size_a - pos;
                while (pos-- > 0)
                    rra(stack_a);
            }
            pb(stack_a, stack_b);
            i++;
            if (i == 5)
                break;
        }
        current = current->next;
    }
    max = find_max(stack_b);
    current = (*stack_b);
    while(current->next != NULL)
    {
        if (current->value == max)
        {
            pos = find_position(stack_b, current->value);
            while(pos > 0)
            {
                rb(stack_b);
                pos--;
            }
            pa(stack_a, stack_b);
        }
        current = current->next;
    }
}

    

void ft_algo(list **stack_a, list **stack_b, int size)
{
    if (size == 3)
    {
        ft_trois(stack_a);
    }
    if (size == 5)
    {
        ft_cinq(stack_a, stack_b);
    }
    if (size < 100 && size > 5)
    {
        ft_centetmoin(stack_a, stack_b);
    }
}

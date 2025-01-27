/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:14:27 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/22 16:05:42 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ra(list **stack_a)
{
	list *temp;
	list *cur;
	ft_printf("ra\n");
	if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
	temp = *stack_a;
    *stack_a = temp->next;
    temp->next = NULL;

    cur = *stack_a;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}
void rb(list **stack_b)
{
	list *temp;
	list *cur;
	ft_printf("rb\n");
	if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
	temp = *stack_b;
    *stack_b = temp->next;
    temp->next = NULL;

    cur = *stack_b;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}
void rr(list **stack_a, list **stack_b)
{
	ft_printf("rr\n");
	rb(stack_b);
	ra(stack_a);
}
void rra(list **stack_a)
{
	list *temp = NULL;
	list *cur;
	ft_printf("rra\n");
	if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
	cur = *stack_a;
	while (cur->next != NULL)
    {
        temp = cur;
        cur = cur->next;
    }
    temp->next = NULL;
    cur->next = *stack_a;
    *stack_a = cur;
}
void rrb(list **stack_b)
{
	list *temp = NULL;
	list *cur;
	ft_printf("rrb\n");
	if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
	cur = *stack_b;
	while(cur->next != NULL)
	{
		temp = cur;
		cur = cur->next;
	}
	temp->next = NULL;
    cur->next = *stack_b;
    *stack_b = cur;
}

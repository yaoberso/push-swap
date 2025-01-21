/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:14:27 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/20 19:39:34 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ra(list **stack_a)
{
	ft_printf("ra\n");
	list *temp;
	list *cur;
	temp = *stack_a;
	cur = *stack_a;
	*stack_a = temp->next;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = temp;
	temp->next = NULL;
}
void rb(list **stack_b)
{
	ft_printf("rb\n");
	list *temp;
	list *cur;
	temp = *stack_b;
	cur = *stack_b;
	*stack_b = temp->next;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = temp;
	temp->next = NULL;
}
void rr(list **stack_a, list **stack_b)
{
	ft_printf("rr\n");
	rb(stack_b);
	ra(stack_a);
}
void rra(list **stack_a)
{
	ft_printf("rra\n");
	list *temp = NULL;
	list *cur;
	cur = *stack_a;
	while(cur->next != NULL)
	{
		temp = cur;
		cur = cur->next;
	}
	cur->next = *stack_a;
	*stack_a = cur;
	temp->next = NULL;
}
void rrb(list **stack_b)
{
	ft_printf("rrb\n");
	list *temp = NULL;
	list *cur;
	cur = *stack_b;
	while(cur->next != NULL)
	{
		temp = cur;
		cur = cur->next;
	}
	cur->next = *stack_b;
	*stack_b = cur;
	temp->next = NULL;
}

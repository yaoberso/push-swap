/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:44 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/20 19:39:53 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sa(list *current)
{
	ft_printf("sa\n");
	if (!current || !current->next)
		return ;
	int temp;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}

void sb(list *current)
{
	ft_printf("sb\n");
	if (!current || !current->next)
		return ;
	int temp;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}
void ss(list *current)
{
	ft_printf("ss\n");
	sb(current);
	sa(current);
}
void pa(list **stack_a, list **stack_b)
{
	ft_printf("pa\n");
	if(*stack_b == NULL)
	{
		return ;
	}
	list *temp;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}
void pb(list **stack_a, list **stack_b)
{
	ft_printf("pb\n");
	if(*stack_a == NULL)
	{
		return ;
	}
	list *temp;
	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	(*stack_b) = temp;
}



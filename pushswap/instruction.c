/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:44 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:18:10 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *current)
{
	int	temp;

	ft_printf("sa\n");
	if (!current || !current->next)
		return ;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}

void	sb(t_list *current)
{
	int	temp;

	ft_printf("sb\n");
	if (!current || !current->next)
		return ;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}

void	ss(t_list *current)
{
	ft_printf("ss\n");
	sb(current);
	sa(current);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	ft_printf("pa\n");
	if (*stack_b == NULL)
	{
		return ;
	}
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	ft_printf("pb\n");
	if (*stack_a == NULL)
	{
		return ;
	}
	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	(*stack_b) = temp;
}

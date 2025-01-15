/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:07 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/15 13:41:39 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "printf/ft_printf.h"

typedef struct list {
	int value;
	struct list *next;
} list;

void stockpile(int argc, char **argv, list **head);
void ft_quicksort(list **stack_a, list **stack_b);
int ft_checktri(list **stack_a);
int ft_take_pivot(list **stack);
long int ft_atoi(char *str);
void sa(list *current);
void sb(list *current);
void ss(list *current);
void pa(list **stack_a, list **stack_b);
void pb(list **stack_a, list **stack_b);
void ra(list **stack_a);
void rb(list **stack_b);
void rr(list **stack_a, list **stack_b);
void rra(list **stack_a);
void rrb(list **stack_b);
void rrr(list **stack_a, list **stack_b);

#endif
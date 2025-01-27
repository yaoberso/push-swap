/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:07 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/26 14:36:17 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "printf/ft_printf.h"

typedef struct s_list {
	int value;
	struct s_list *next;
} list;

void free_chunk(int **chunk, int size);
int find_position(list **stack_a, int value);
int **set_chunk(int min, int max, int nb_chunk);
int stack_size(list *stack);
int find_min(list **stack);
int find_max(list **stack);
int find_min_position(list *stack);
int find_max_position(list *stack);
void check_error(char **argv);
void free_stack(list *stack);
void print_stack(list *stack);
void stockpile(int argc, char **argv, list **head);
void ft_algo(list **stack_a, list **stack_b, int size);
int ft_checktri(list **stack_a);
int ft_take_pivot(list **stack, int size);
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
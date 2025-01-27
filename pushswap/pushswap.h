/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:07 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:00 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "printf/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

void				ft_set_chunk_free(int **chunks, int i);
void				ft_set_chunk_fill_chunk(int *chunk, int *min, int interval,
						int i, int nb_chunk, int max);
int					*ft_set_chunk_allocate_chunk(void);
int					**ft_set_chunk_malloc(int nb_chunk);
int					**ft_plusde5_set_chunks(t_list **stack_a, int nb_chunk);
void				ft_plusde5_chunk_sort(t_list **stack_a, t_list **stack_b,
						int **chunks, int nb_chunk);
void				ft_plusde5_free_chunks(int **chunks, int nb_chunk);
void				ft_plusde5_stack_b_sort(t_list **stack_a, t_list **stack_b);
void				ft_cinq_move_max(t_list **stack_a, t_list **stack_b);
void				ft_cinq_move_min(t_list **stack_a, t_list **stack_b);
void				transform_to_index(t_list **head);
void				free_chunk(int **chunk, int size);
int					find_position(t_list **stack_a, int value);
int					**set_chunk(int min, int max, int nb_chunk);
int					stack_size(t_list *stack);
int					find_min(t_list **stack);
int					find_max(t_list **stack);
int					find_min_position(t_list *stack);
int					find_max_position(t_list *stack);
void				check_error(char **argv);
void				free_stack(t_list *stack);
void				stockpile(int argc, char **argv, t_list **head);
void				ft_algo(t_list **stack_a, t_list **stack_b, int size);
long int			ft_atoi(char *str);
void				sa(t_list *current);
void				sb(t_list *current);
void				ss(t_list *current);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

#endif
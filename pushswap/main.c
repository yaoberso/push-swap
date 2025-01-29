/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/29 09:26:13 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stockpile(int argc, char **argv, t_list **head, int v)
{
	int		i;
	t_list	*current;

	i = 1;
	current = NULL;
	*head = malloc(sizeof(t_list));
	if (!(*head))
		return ;
	if (v == 0)
	{
		i = 2;
		(*head)->value = ft_atoi(argv[1]);
	}
	else
		(*head)->value = ft_atoi(argv[0]);
	(*head)->next = NULL;
	current = (*head);
	while (i < argc)
	{
		current->next = malloc(sizeof(t_list));
		if (!current->next)
			return ;
		current = current->next;
		current->value = ft_atoi(argv[i]);
		current->next = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**arg;
	int		split_size;
	int		i;

	i = 0;
	arg = NULL;
	stack_a = NULL;
	stack_b = NULL;
	split_size = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		i = 1;
		arg = ft_split(argv[1]);
		split_size = ft_count(arg);
		if (split_size > 1)
			argv = arg;
		else
		{
			free_split(arg);
			return (0);
		}
	}
	if (split_size > 0)
		size = split_size;
	else
		size = argc;
	check_error(argv);
	stockpile(size, argv, &stack_a, i);
	transform_to_index(&stack_a);
	if (!arg)
		size = size - 1;
	ft_algo(&stack_a, &stack_b, size);
	free_stack(stack_a);
	if (arg)
		free_split(arg);
	return (0);
}

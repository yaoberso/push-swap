/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:59 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/27 14:18:37 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stockpile(int argc, char **argv, t_list **head)
{
	int		i;
	t_list	*current;

	current = NULL;
	i = 2;
	*head = malloc(sizeof(t_list));
	if (!(*head))
	{
		ft_printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	(*head)->value = ft_atoi(argv[1]);
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

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	size = argc - 1;
	check_error(argv);
	stockpile(argc, argv, &stack_a);
	transform_to_index(&stack_a);
	ft_algo(&stack_a, &stack_b, size);
	free_stack(stack_a);
	return (0);
}

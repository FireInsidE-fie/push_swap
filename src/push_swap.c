/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:24 by estettle          #+#    #+#             */
/*   Updated: 2024/11/14 12:57:30 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_kill(t_slab **stack1, t_slab **stack2, int error_code)
{
	stack_clear(stack1);
	stack_clear(stack2);
	if (error_code != 0)
		write(2, "Error\n", 6);
	exit(error_code);
}

void	print_stack(t_slab **list)
{
	t_slab	*slab;

	if (!list || !(*list))
		return ;
	slab = *list;
	while (slab)
	{
		printf("%ld\n", slab->number);
		slab = slab->next;
	}
	printf("---\n"); // DON'T FORGET TO REPLACE WITH FT_PRINTF
}

int	main(int argc, char **argv)
{
	t_slab	**stack1;
	t_slab	**stack2;

	if (argc < 2)
		return (-1);
	// Check if input is good (only ints, no bigger no smaller, no dupes)
	stack1 = parse_input(argc, argv);
	stack2 = 0;
	print_stack(stack1);
	ft_sa(stack1, stack2);
	print_stack(stack1);
	ft_sa(stack1, stack2);
	print_stack(stack1);
	ft_rra(stack1, stack2);
	print_stack(stack1);
	ft_rra(stack1, stack2);
	print_stack(stack1);
	ft_rra(stack1, stack2);
	ft_rra(stack1, stack2);
	ft_rra(stack1, stack2);
	print_stack(stack1);

	ft_kill(stack1, stack2, 0);
}

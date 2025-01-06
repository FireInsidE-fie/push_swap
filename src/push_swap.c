/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:24 by estettle          #+#    #+#             */
/*   Updated: 2025/01/06 15:13:12 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Kills the program while freeing stacks' memory and displays
 * an error message if applicable.
 *
 * @note Note that both stacks can be NULL in case the program needs to close
 * but hasn't initialized its stacks just yet.
 *
 * @param stack1 The first stack to clear.
 * @param stack2 The second stack to clear.
 * @param error_code The exit status code to pass to the exit() function.
 * If error_code == 0, the program will exit without printing "Error\n".
 */
void	ft_kill(t_slab **stack1, t_slab **stack2, int error_code)
{
	stack_clear(stack1);
	stack_clear(stack2);
	if (error_code != 0)
		write(2, "Error\n", 6);
	exit(error_code);
}

/**
 * @brief Prints a given stack from top to bottom to stdout, followed by three
 * dashes.
 *
 * @param list A pointer to the first element of the stack.
 */
void	print_stack(t_slab **list)
{
	t_slab	*slab;

	if (!list || !(*list))
		return ;
	ft_printf("---\n");
	slab = *list;
	while (slab)
	{
		ft_printf("%d : %d\n", slab->final_position, slab->number);
		slab = slab->next;
	}
}

int	main(int argc, char **argv)
{
	int32_t	nb_count;
	t_slab	**stack1;
	t_slab	**stack2;

	if (argc < 2)
		return (-1);
	stack1 = parse_input(argc, argv);
	stack2 = malloc(sizeof(t_slab *));
	if (is_sorted(*stack1))
		ft_kill(stack1, stack2, 0);
	nb_count = slab_count(*stack1);
	if (!stack2)
		ft_kill(stack1, NULL, -1);
	*stack2 = NULL;
	if (nb_count == 2)
		ft_alis(stack1, stack2);
	else if (nb_count == 3)
		ft_roxy(stack1, stack2);
	else if (nb_count == 4)
		ft_ash(stack1, stack2);
	else if (nb_count == 5)
		ft_melody(stack1, stack2);
	else
		ft_reflection(stack1, stack2);
		// ft_radix(stack1, stack2);
	ft_kill(stack1, stack2, 0);
}

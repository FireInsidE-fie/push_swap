/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:46:51 by estettle          #+#    #+#             */
/*   Updated: 2024/11/12 17:46:09 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Linked list element definition
typedef struct s_slab
{
	int				number;
	struct s_slab	*next;
}	t_slab;

// Operation function prototypes
void	ft_sa(t_slab **stack1, t_slab **stack2);
void	ft_sb(t_slab **stack1, t_slab **stack2);
void	ft_ss(t_slab **stack1, t_slab **stack2);
void	ft_pa(t_slab **stack1, t_slab **stack2);
void	ft_pb(t_slab **stack1, t_slab **stack2);
void	ft_ra(t_slab **stack1, t_slab **stack2);
void	ft_rb(t_slab **stack1, t_slab **stack2);
void	ft_rr(t_slab **stack1, t_slab **stack2);
void	ft_rra(t_slab **stack1, t_slab **stack2);
void	ft_rrb(t_slab **stack1, t_slab **stack2);
void	ft_rrr(t_slab **stack1, t_slab **stack2);

// Input parsing function prototypes
t_slab	**parse_input(int argc, char **argv);

// Chained lists management function prototypes
t_slab	*slab_new(int nb);
t_slab	*slab_last(t_slab *lst);
void	slab_add_back(t_slab **lst, t_slab *new);
void	slab_add_front(t_slab **lst, t_slab *new);


#endif // PUSH_SWAP_H

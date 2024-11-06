/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:46:51 by estettle          #+#    #+#             */
/*   Updated: 2024/11/06 13:15:23 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Linked list element definition
typedef struct	s_slab
{
	int				number;
	struct s_slab	*next;
} t_slab;

// Libft
# include "../libft/libft.h"

// Operation function prototypes
void ft_sa(t_slab **stack1, t_slab **stack2);
void ft_sb(t_slab **stack1, t_slab **stack2);
void ft_ss(t_slab **stack1, t_slab **stack2);
void ft_pa(t_slab **stack1, t_slab **stack2);
void ft_pb(t_slab **stack1, t_slab **stack2);
void ft_ra(t_slab **stack1, t_slab **stack2);
void ft_rb(t_slab **stack1, t_slab **stack2);
void ft_rr(t_slab **stack1, t_slab **stack2);
void ft_rra(t_slab **stack1, t_slab **stack2);
void ft_rrb(t_slab **stack1, t_slab **stack2);
void ft_rrr(t_slab **stack1, t_slab **stack2);

#endif // PUSH_SWAP_H

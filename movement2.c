/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:47:57 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:17 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	double_rotate(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

void	rrotate_a(t_list **a)
{
	ft_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_list **b)
{
	ft_rrotate(b);
	write(1, "rrb\n", 4);
}

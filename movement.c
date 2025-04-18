/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:10:26 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:09 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	double_swap(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:47:43 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 22:25:21 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_half(t_list **a, t_list **b, int size)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	int		mid;
	int		tmp;

	mid = size / 2;
	tmp = mid + 1;
	while (mid > 0 && tmp <= size)
	{
		ptr_a = *a;
		ptr_b = *b;
		if (ptr_b->index == mid && ptr_a->index == tmp)
		{
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
			tmp++;
			mid--;
		}
		else if (ptr_b->index != mid || ptr_a->index != tmp)
			return (0);
	}
	return (1);
}

int	is_sorted(t_list **a)
{
	t_list	*ptr;
	int		i;

	ptr = *a;
	i = 1;
	if (!ptr)
		return (0);
	/* while (i < size)
	{
		if (ptr->index != i)
			return (0);
		ptr = ptr->next;
		i++;
	} */
	while (ptr)
	{
		if (ptr->index != i)
			return (0);
		ptr = ptr->next;
		i++;
	}
	return (1);
}

void	push_to_finish(t_list **a, t_list **b, int size)
{
	int	i;

	i = size / 2;
	while (i > 0)
	{
		push_a(a, b);
		i--;
	}
}

void	algo_push(t_list **a, t_list **b, int a_or_b)
{
	int	res;

	res = 32;
	if (a_or_b == 0)
	{
		push_b(a, b);
		res = check_bm1(a);
		if (res == 1)
			swap_a(a);
		else if (res == 2)
			rotate_a(a);
		else if (res == 3)
			rrotate_a(a);
		push_a(a, b);
	}
	else if (a_or_b == 1)
	{
		push_a(a, b);
		if (check_bm2(b) == 1)
			swap_b(b);
		else if (check_bm2(b) == 2)
			rotate_b(b);
		else if (check_bm2(b) == 3)
			rrotate_b(b);
		push_b(a, b);
	}
}

void	easy_sort2(t_list **a, t_list **b)
{
	int	res;

	res = 32;
	while (!is_sorted(a))
	{
		res = check_bm1(a);
		if (res == 0)
			algo_push(a, b, 0);
		else if (res == 1)
			swap_a(a);
		else if (res == 2)
			rotate_a(a);
		else if (res == 3)
			rrotate_a(a);
	}
}

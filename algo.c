/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:42:08 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 22:32:50 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_main(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(a))
		return ;
	if (size <= 9)
	{
		easy_sort2(a, b);
		return ;
	}
	else if (size > 9)
	{
		algo_push_half(a, b, size);
		easy_sort(a, b, size);
		return ;
	}
}

void	algo_push_half(t_list **a, t_list **b, int size)
{
	t_list	*ptr;
	int		mid;

	ptr = *a;
	mid = size / 2;
	while (ptr->next != NULL)
	{
		if (ptr->index <= mid)
		{
			ptr = ptr->next;
			push_b(a, b);
		}
		else if (ptr->index > mid)
		{
			ptr = ptr->next;
			rotate_a(a);
		}
	}
}

void	easy_sort(t_list **a, t_list **b, int size)
{
	while (!is_sorted_half(a, b, size))
	{
		if (check_bm1(a) == 0)
			algo_push(a, b, 0);
		else if (check_bm2(b) == 0)
			algo_push(a, b, 1);
		else if (check_bm1(a) == 1 && check_bm2(b) == 1)
			double_swap(a, b);
		else if (check_bm1(a) == 2 && check_bm2(b) == 2)
			double_rotate(a, b);
		else if (check_bm1(a) == 3 && check_bm2(b) == 3)
			double_rrotate(a, b);
		else if (check_bm1(a) == 1)
			swap_a(a);
		else if (check_bm1(a) == 2)
			rotate_a(a);
		else if (check_bm1(a) == 3)
			rrotate_a(a);
		else if (check_bm2(b) == 1)
			swap_b(b);
		else if (check_bm2(b) == 2)
			rotate_b(b);
		else if (check_bm2(b) == 3)
			rrotate_b(b);
	}
	push_to_finish(a, b, size);
}

int	check_bm1(t_list **list)
{
	t_list	*ptr;
	t_list	*last;
	t_list	*head;

	last = ft_lstlast(list);
	head = *list;
	ptr = head->next;
	if (head->index > ptr->index)
		return (1);
	else if (head->index < last->index)
		return (2);
	else if (head->index > last->index)
		return (3);
	return (0);
}

int	check_bm2(t_list **list)
{
	t_list	*ptr;
	t_list	*last;
	t_list	*head;

	last = ft_lstlast(list);
	head = *list;
	ptr = head->next;
	if (head->index < ptr->index)
		return (1);
	else if (head->index > ptr->index && head->index > last->index)
		return (2);
	else if (head->index > ptr->index && head->index < last->index)
		return (3);
	return (0);
}

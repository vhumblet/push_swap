/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:02:25 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:21 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rrotate(t_list **a, t_list **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	write(1, "rrr\n", 4);
}

void	ft_swap(t_list **list)
{
	t_list	*head_list;
	t_list	*node_2;
	t_list	*node_3;

	head_list = *list;
	node_2 = *list;
	node_2 = node_2->next;
	node_3 = node_2->next;
	node_2->next = head_list;
	head_list->next = node_3;
}

void	ft_push(t_list **list1, t_list **list2)
{
	t_list	*head_1;
	t_list	*tmp;
	t_list	*node_2;

	head_1 = *list1;
	tmp = *list2;
	node_2 = tmp->next;
	*list2 = node_2;
	*list1 = tmp;
	tmp = head_1;
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*bottom;

	tmp = *list;
	*list = tmp->next;
	bottom = tmp->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = tmp;
	tmp->next = NULL;
}

void	ft_rrotate(t_list **list)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*bottom;

	head = *list;
	bottom = head->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
	tmp = head->next;
	while (tmp->next != bottom)
		tmp = tmp->next;
	tmp->next = NULL;
	bottom->next = head;
	*list = bottom;
}

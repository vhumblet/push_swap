/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:02:25 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 21:40:49 by vhumblet         ###   ########.fr       */
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
	*list = node_2;
}

void	ft_push(t_list **list1, t_list **list2)
{
	t_list	*head_1;
	t_list	*tmp;

	if (!*list1)
		return ;
	head_1 = *list1;
	tmp = *list1;
	if (!(head_1->next == NULL))
		head_1 = head_1->next;
	tmp->next = *list2;
	*list1 = head_1;
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*bottom;

	if ((*list)->next == NULL)
		return ;
	tmp = *list;
	*list = tmp->next;
	bottom = ft_lstlast(list);
	bottom->next = tmp;
	tmp->next = NULL;
}

void	ft_rrotate(t_list **list)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*bottom;

	if (!list || !*list)
		return ;
	head = *list;
	bottom = ft_lstlast(list);
	tmp = head;
	while (tmp->next != bottom)
		tmp = tmp->next;
	tmp->next = NULL;
	bottom->next = *list;
	*list = bottom;
}

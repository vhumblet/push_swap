/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:01:59 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:27 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strs_to_list(char **str, t_list **list)
{
	char	**tmp;
	t_list	*new_node;
	int		i;
	int		j;

	i = 0;
	while (str[++i])
	{
		tmp = ft_split(str[i], ' ');
		j = -1;
		while (tmp[++j])
		{
			new_node = ft_lstnew(str[i]);
			ft_lstadd_back(list, new_node);
		}
		j = -1;
		while (tmp[++j])
			ft_feel_free((void *)tmp[j]);
	}
}

t_list	*ft_lstnew(char *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->str = content;
	return (rtn);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (*lst)
	{
		t = ft_lstlast(*lst);
		t->next = &*new;
	}
	else
		*lst = new;
}

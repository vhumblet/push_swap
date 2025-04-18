/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feel_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:02:37 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:39:53 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_feel_free(void **ptr)
{
	if (*ptr && ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	else if (*ptr && !ptr)
		ptr = NULL;
}

void	free_list(t_list **list)
{
	t_list	*ptr;
	t_list	*ptr_next;

	ptr = *list;
	ptr_next = ptr->next;
	while (ptr_next->next != NULL)
	{
		ft_feel_free((void *)ptr->str);
		ft_feel_free((void *)ptr);
		ptr = ptr_next;
		ptr_next = ptr_next->next;
	}
	ft_feel_free((void *)ptr_next->str);
	ft_feel_free((void *)ptr_next);
}

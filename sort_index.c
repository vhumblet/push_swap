/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:41:21 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:42 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_make_array(t_list **list, int nb)
{
	long	*array;
	int		i;
	t_list	*ptr;

	i = -1;
	ptr = *list;
	array = (long *)malloc(sizeof(long) * nb);
	while (++i < nb)
	{
		array[i] = ft_atol(ptr->str);
		ptr = ptr->next;
	}
	return (array);
}

void	ft_sort_array(long *array)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i] < array[j] && j < i)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			j++;
		}
		i++;
	}
}

void	ft_put_index(t_list **list, long *array)
{
	int		i;
	t_list	*ptr;

	i = -1;
	ptr = *list;
	while (array[++i])
	{
		while (ft_atol(ptr->str) != array[i])
		{
			ptr = ptr->next;
			if (ptr->next == NULL)
				ptr = *list;
		}
		if (ft_atol(ptr->str) == array[i])
		{
			ptr->index = i + 1;
			ptr = ptr->next;
			if (ptr->next == NULL)
				ptr = *list;
		}
	}
}

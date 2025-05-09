/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:41:21 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 16:54:33 by vhumblet         ###   ########.fr       */
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

void	ft_sort_array(long *array, int nb)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < i)
		{
			if (array[i] < array[j])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}
	print_array(array, nb);
}

void	ft_put_index(t_list **list, long *array, int size)
{
	int		i;
	t_list	*ptr;

	i = -1;
	ptr = *list;
	while (++i < size)
	{
		while (ft_atol(ptr->str) != array[i])
		{
			if (ptr && ptr->next == NULL)
				ptr = *list;
			else
				ptr = ptr->next;
		}
		if (ft_atol(ptr->str) == array[i])
		{
			ptr->index = i + 1;
			if (ptr && ptr->next == NULL)
				ptr = *list;
			else
				ptr = ptr->next;
		}
	}
	print_array(array, size);
}

void	print_array(long *array, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		printf("%ld\n", array[i]);
}

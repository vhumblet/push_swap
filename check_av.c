/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:00:34 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 16:59:08 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_av(t_list **list)
{
	t_list	*ptr;
	int		len;

	ptr = *list;
	while (ptr->next != NULL)
	{
		len = ft_strlen(ptr->str);
		if (!ft_isdigit(ptr->str) || len > 11)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	check_int_max_min(long *array, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		if (array[i] > 2147483647 || array[i] < -2147483648)
			return (0);
	return (1);
}

int	check_double(long *array, int nb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
	}
	return (1);
}

int	error_and_index(t_list **list)
{
	long	*array;
	t_list	*ptr;
	int		size;

	ptr = *list;
	size = ft_lstsize(ptr);
	array = ft_make_array(&ptr, size);
	if (!check_double(array, size) || !check_int_max_min(array, size))
		return (0);
	ft_sort_array(array, size);
	ft_put_index(&ptr, array, size);
	ft_feel_free((void *)array);
	return (1);
}

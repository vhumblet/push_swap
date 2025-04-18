/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:00:34 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:39:39 by vhumblet         ###   ########.fr       */
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

int	check_int_max_min(long *array)
{
	int	i;

	i = -1;
	while (array[++i])
		if (array[i] > 2147483647 || array[i] < -2147483648)
			return (0);
	return (1);
}

int	check_double(long *array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = i + 1;
		while (array[j])
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

	ptr = *list;
	array = ft_make_array(&ptr, ft_lstsize(ptr));
	if (!check_double(array) || !check_int_max_min(array))
		return (0);
	ft_sort_array(array);
	ft_put_index(&ptr, array);
	ft_feel_free((void *)array);
	return (1);
}

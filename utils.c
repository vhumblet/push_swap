/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:49:34 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:41:00 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	return_atol_unll(unsigned long long nb_llu, int sign, int size,
		int count)
{
	unsigned long long	max;

	max = 922337203854775807;
	if (count > 1)
		return (0);
	else if (((nb_llu > max) && size > 18) && sign > 0)
		return (-1);
	else if (((nb_llu > (max + 1)) && size > 18) && sign < 0)
		return (0);
	return (nb_llu * sign);
}

long	ft_atol(const char *str)
{
	unsigned long long	nb_llu;
	int					i;
	int					sign;
	int					count;
	int					size;

	nb_llu = 0;
	i = 0;
	sign = 1;
	count = 0;
	size = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
		count++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57 && ++size)
		nb_llu = nb_llu * 10 + str[i++] - 48;
	return (return_atol_unll(nb_llu, sign, size, count));
}

int	ft_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (1);
	}
	return (0);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

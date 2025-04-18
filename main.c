/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:49:15 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:02 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	stack_a;
	t_list	stack_b;
	t_list	*ptr;
	t_list	*ptrb;

	stack_a.next = NULL;
	stack_b.next = NULL;
	*ptr = stack_a;
	*ptrb = stack_b;
	strs_to_list(av, ptr);
	if (!check_digit_av(ptr) || !error_and_index(ptr))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	algo_main(ptr, ptrb);
}

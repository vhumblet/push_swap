/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:49:15 by vhumblet          #+#    #+#             */
/*   Updated: 2025/05/08 21:18:15 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	(void)ac;
	stack_a = NULL;
	stack_b = NULL;
	strs_to_list(av, &stack_a);
	if (!check_digit_av(&stack_a) || !error_and_index(&stack_a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	algo_main(&stack_a, &stack_b);
	return (0);
}

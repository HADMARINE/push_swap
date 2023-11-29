/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/30 00:25:04 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Make sure that you get la size bigger than 3
static bool	send_b_except_three(t_list **la, t_list **lb)
{
	size_t	size;
	size_t	i;

	size = ft_lstsize(*la) - 3;
	i = 0;
	while (i < size)
	{
		push_b(la, lb);
		i++;
	}
	return (true);
}

void	execution(t_list **la, t_list **lb)
{
	bool		is_sorted;
	t_ab_value	val;

	if (send_b_except_three(la, lb) == false)
		return ;
	sort_three_elements(la, STACK_TYPE_A);
	is_sorted = false;
	while (is_sorted == false || *lb != NULL)
	{
		// print_lists(*la, *lb);
		val = get_smallest_cost(la, lb);
		execute_by_command(val, la, lb);
		is_sorted = verify_sorted(*la);
	}
}

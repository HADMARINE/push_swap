/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 12:41:00 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execution(t_list **la, t_list **lb)
{
	bool			is_sorted;
	t_stack_type	stack;
	int				size;

	size = 2;
	stack = STACK_TYPE_A;
	is_sorted = false;
	while (is_sorted == false || *lb != NULL)
	{
		if (stack == STACK_TYPE_A)
		{
			merge_sort(la, lb, STACK_TYPE_B, size);
			stack = STACK_TYPE_B;
		}
		else
		{
			merge_sort(lb, la, STACK_TYPE_A, size);
			stack = STACK_TYPE_A;
		}
		size *= 2;
		if (*la)
			is_sorted = verify_sorted(*la);
	}
}

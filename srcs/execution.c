/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 14:15:33 by lhojoon          ###   ########.fr       */
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
		merge_sort(la, lb, stack, size);
		if (stack == STACK_TYPE_A)
			stack = STACK_TYPE_B;
		else
			stack = STACK_TYPE_A;
		size *= 2;
		if (*la)
			is_sorted = verify_sorted(*la);
	}
}

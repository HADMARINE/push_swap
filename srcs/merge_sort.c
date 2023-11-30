/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:02:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/30 18:08:33 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	inverse_result(bool val, bool effective)
{
	if (effective)
		return (!val);
	else
		return (val);
}

void	merge_sort(t_list **ps, t_list **pd, t_stack_type type, int size)
{
	bool	is_even;
	int		i;
	int		head_limit;
	int		tail_limit;

	is_even = false;
	while (ft_lstsize(*ps) >= size)
	{
		i = 0;
		head_limit = size / 2;
		tail_limit = head_limit;
		while (i < size)
		{
			if (type == STACK_TYPE_A)
			{
				if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
				{
					reverse_rotate_b(ps);
					push_a(pd, ps);
					tail_limit--;
				}
				else
				{
					push_a(pd, ps);
					head_limit--;
				}
			}
			else
			{
				if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
				{
					reverse_rotate_a(ps);
					push_b(ps, pd);
				}
				else
				{
					push_b(ps, pd);
				}
			}
			i++;
		}
		is_even = !is_even;
	}
	if (*ps)
	{
		while (*ps)
		{
			if (type == STACK_TYPE_A)
				push_a(pd, ps);
			else
				push_b(ps, pd);
		}
	}
}

//  a -> b Incrementant
//  b -> a Incrementant 


// A
// 6 4  2 3  1 5
// B
// 2 3 | 4 1 | 5 6

// B
// 2 3 | 4 1 | 5 6
// A
// 1 4 5 6 | 3 2


// B
// 6 5 4 3 2 1
// A
// 1 2 3 4 5 6 #



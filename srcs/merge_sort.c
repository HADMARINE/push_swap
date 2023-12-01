/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:02:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 12:52:45 by lhojoon          ###   ########.fr       */
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

static void	push_residues(t_list **ps, t_list **pd, int size, t_stack_type type)
{
	int	len;
	int	i;

	len = ft_lstsize(*ps) % size;
	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		if (type == STACK_TYPE_A)
		{
			reverse_rotate_a(ps);
			push_a(pd, ps);
		}
		else
		{
			reverse_rotate_b(ps);
			push_b(ps, pd);
		}
		i++;
	}
}

/**
 * ps : la
 * pd : lb
*/
static void	residues_cleaning(t_list **ps, t_list **pd, int size)
{
	int			len;
	int			i;
	t_ab_value	value;

	len = ft_lstsize(*ps) % (size / 2);
	i = 0;
	while (i < len)
	{
		reverse_rotate_a(ps);
		push_b(ps, pd);
		i++;
	}
	while (*pd)
	{
		value = get_smallest_cost(ps, pd);
		execute_by_command(value, ps, pd);
	}
}

void	merge_sort(t_list **ps, t_list **pd, t_stack_type type, int size)
{
	bool	is_even;
	int		i;
	int		head_limit;
	int		tail_limit;

	is_even = true;
	if (size > ft_lstsize(*ps) && type == STACK_TYPE_B)
	{
		residues_cleaning(ps, pd, size);
		return ;
	}
	push_residues(ps, pd, size, type);
	while (ft_lstsize(*ps) >= size)
	{
		i = 0;
		head_limit = size / 2;
		tail_limit = head_limit;
		while (i < size)
		{
			if (type == STACK_TYPE_B)
			{
				if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
				{
					reverse_rotate_a(ps);
					push_b(ps, pd);
					tail_limit--;
				}
				else
				{
					push_b(ps, pd);
					head_limit--;
				}
			}
			else
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
			i++;
		}
		is_even = !is_even;
	}
}

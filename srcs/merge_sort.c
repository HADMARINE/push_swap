/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:02:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 16:11:16 by lhojoon          ###   ########.fr       */
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

static void	push_residues(t_list **la, t_list **lb, int size, t_stack_type type)
{
	int	len;
	int	i;

	if (type == STACK_TYPE_A)
		len = ft_lstsize(*lb) % size;
	else
		len = ft_lstsize(*la) % size;
	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		if (type == STACK_TYPE_A)
		{
			reverse_rotate_b(lb);
			push_a(la, lb);
		}
		else
		{
			reverse_rotate_a(la);
			push_b(la, lb);
		}
		i++;
	}
}

/**
 * ps : la
 * pd : lb
*/
static void	residues_cleaning(t_list **la, t_list **lb, int size, t_stack_type type)
{
	int			len;
	int			i;
	t_ab_value	value;

	i = 0;
	if (type == STACK_TYPE_A)
	{
		len = ft_lstsize(*la) % (size / 2);
		while (i < len)
		{
			reverse_rotate_a(la);
			push_a(la, lb);
			i++;
		}
		while (*lb)
		{
			value = get_smallest_cost(la, lb);
			execute_by_command(value, la, lb, type);
		}
	}
	else
	{
		len = ft_lstsize(*lb) % (size / 2);
		while (i < len)
		{
			reverse_rotate_b(lb);
			push_b(la, lb);
			i++;
		}
		while (*la)
		{
			value = get_smallest_cost(lb, la);
			execute_by_command(value, lb, la, type);
		}
	}
}

// void	merge_sort(t_list **ps, t_list **pd, t_stack_type type, int size)
// {
// 	bool	is_even;
// 	int		i;
// 	int		head_limit;
// 	int		tail_limit;

// 	is_even = true;
// 	if (size > ft_lstsize(*ps) && type == STACK_TYPE_B)
// 	{
// 		residues_cleaning(ps, pd, size);
// 		return ;
// 	}
// 	push_residues(ps, pd, size, type);
// 	while (ft_lstsize(*ps) >= size)
// 	{
// 		i = 0;
// 		head_limit = size / 2;
// 		tail_limit = head_limit;
// 		while (i < size)
// 		{
// 			if (type == STACK_TYPE_B)
// 			{
// 				if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
// 				{
// 					reverse_rotate_a(ps);
// 					push_b(ps, pd);
// 					tail_limit--;
// 				}
// 				else
// 				{
// 					push_b(ps, pd);
// 					head_limit--;
// 				}
// 			}
// 			else
// 			{ // A : ps -> la, pd->lb
// 				if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
// 				{
// 					reverse_rotate_b(ps);
// 					push_a(pd, ps);
// 					tail_limit--;
// 				}
// 				else
// 				{
// 					push_a(pd, ps);
// 					head_limit--;
// 				}
// 			}
// 			i++;
// 		}
// 		is_even = !is_even;
// 	}
// }

static void	send_a_inversed(t_list **la, t_list **lb)
{
	while (*lb)
	{
		reverse_rotate_b(lb);
		push_a(la, lb);
	}
}

void	merge_sort(t_list **la, t_list **lb, t_stack_type type, int size)
{
	bool	is_even;
	int		i;
	int		head_limit;
	int		tail_limit;

	print_lists(*la, *lb);
	is_even = true;
	if (type == STACK_TYPE_A)
	{
		push_residues(lb, la, size, type);
		if (size > ft_lstsize(*la) && *lb)
			return (residues_cleaning(la, lb, size, type));
		while (ft_lstsize(*la) >= size)
		{
			i = 0;
			head_limit = size / 2;
			tail_limit = head_limit;
			while (i < size)
			{
				if ((inverse_result((*((int *)(*la)->content) > *((int *)ft_lstlast(*la)->content)), is_even) && tail_limit) || !head_limit)
				{
					reverse_rotate_a(la);
					push_b(la, lb);
					tail_limit--;
				}
				else
				{
					push_b(la, lb);
					head_limit--;
				}
				i++;
			}
			is_even = !is_even;
		}
	}
	else
	{
		if (*lb && verify_sorted(*lb) == true)
			return (send_a_inversed(la, lb));
		push_residues(la, lb, size, type);
		if (size > ft_lstsize(*lb) && *la)
			return (residues_cleaning(lb, la, size, type));
		while (ft_lstsize(*lb) >= size)
		{
			i = 0;
			head_limit = size / 2;
			tail_limit = head_limit;
			while (i < size)
			{
				if ((inverse_result((*((int *)(*lb)->content) > *((int *)ft_lstlast(*lb)->content)), is_even) && tail_limit) || !head_limit)
				{
					reverse_rotate_b(lb);
					push_a(la, lb);
					tail_limit--;
				}
				else
				{
					push_a(la, lb);
					head_limit--;
				}
				i++;
			}
			is_even = !is_even;
		}
	}
}


				// else
				// {
				// 	if ((inverse_result((*((int *)(*ps)->content) > *((int *)ft_lstlast(*ps)->content)), is_even) && tail_limit) || !head_limit)
				// 	{
				// 		reverse_rotate_b(ps);
				// 		push_a(pd, ps);
				// 		tail_limit--;
				// 	}
				// 	else
				// 	{
				// 		push_a(pd, ps);
				// 		head_limit--;
				// 	}
				// }
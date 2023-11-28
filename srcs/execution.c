/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 21:45:04 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sort_items_a(t_list **lst)
{
	while (true)
	{
		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content))
			swap_a(lst);
		if (verify_sorted(*lst))
			break ;
		if (*((int *)ft_lstlast(*lst)->content) > *((int *)(*lst)->content))
			reverse_rotate_a(lst);
		else
			rotate_a(lst);
		if (verify_sorted(*lst))
			break ;
	}
	return (true);
}

static bool	sort_items_b(t_list **lst)
{
	while (true)
	{
		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content))
			swap_b(lst);
		if (verify_sorted(*lst))
			break ;
		if (*((int *)ft_lstlast(*lst)->content) > *((int *)(*lst)->content))
			reverse_rotate_b(lst);
		else
			rotate_b(lst);
		if (verify_sorted(*lst))
			break ;
	}
	return (true);
}

static bool	send_back_b_to_a(t_list **la, t_list **lb)
{
	while (*lb)
		if (push_a(la, lb) == false)
			return (false);
	return (true);
}

void	execution(t_list **la, t_list **lb)
{
	size_t	lsize;
	size_t	i;

	lsize = ft_lstsize(*la) / 2;
	i = 0;
	while (i++ < lsize)
		push_b(la, lb);
	sort_items_a(la);
	sort_items_b(lb);
	send_back_b_to_a(la, lb);
	sort_items_a(la);
}

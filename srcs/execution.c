/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:41:55 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_items(t_list **lst)
{
	while (true)
	{
		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content))
			swap_elements(lst);
		if (verify_sorted(lst))
			break ;
		if (*((int *)ft_lstlast(*lst)->content) > ((int *)(*lst)->content))
			reverse_rotate_elements(lst);
		else
			rotate_elements(lst);
		if (verify_sorted(lst))
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
	size_t	strl;
	size_t	i;

	strl = ft_strlen(*la);
	i = 0;
	while (i < strl)
		push_b(la, lb);
	sort_items(la);
	sort_items(lb);
	send_back_b_to_a(la, lb);
	sort_items(la);
}

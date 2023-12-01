/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:32:41 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 15:39:36 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	reverse_rotate_elements(t_list **lst)
{
	t_list	*lp;
	t_list	*lp2;

	lp = *lst;
	if (!lp || !lp->next)
		return (false);
	if (lp->next != NULL)
		while (lp->next->next != NULL)
			lp = lp->next;
	lp2 = lp->next;
	lp->next = NULL;
	lp2->next = *lst;
	*lst = lp2;
	return (true);
}

bool	reverse_rotate_by_type(t_list **l, t_stack_type type)
{
	if (type == STACK_TYPE_A)
		return (reverse_rotate_a(l));
	else
		return (reverse_rotate_b(l));
}

bool	reverse_rotate_a(t_list **la)
{
	ft_putstr_fd("rra\n", 1);
	return (reverse_rotate_elements(la));
}

bool	reverse_rotate_b(t_list **lb)
{
	ft_putstr_fd("rrb\n", 1);
	return (reverse_rotate_elements(lb));
}

bool	reverse_rotate_all(t_list **la, t_list **lb)
{
	ft_putstr_fd("rrr\n", 1);
	return (reverse_rotate_elements(la)
		&& reverse_rotate_elements(lb));
}

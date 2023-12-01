/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:25:56 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 15:42:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate_elements(t_list **lst)
{
	t_list	*lp;
	t_list	*lp2;

	lp = *lst;
	if (!lp || !lp->next)
		return (false);
	while (lp->next != NULL)
		lp = lp->next;
	lp->next = *lst;
	lp2 = (*lst)->next;
	(*lst)->next = NULL;
	*lst = lp2;
	return (true);
}

bool	rotate_by_type(t_list **l, t_stack_type type)
{
	if (type == STACK_TYPE_A)
		return (rotate_a(l));
	else
		return (rotate_b(l));
}

bool	rotate_a(t_list **la)
{
	ft_putstr_fd("ra\n", 1);
	return (rotate_elements(la));
}

bool	rotate_b(t_list **lb)
{
	ft_putstr_fd("rb\n", 1);
	return (rotate_elements(lb));
}

bool	rotate_all(t_list **la, t_list **lb)
{
	ft_putstr_fd("rr\n", 1);
	return (rotate_elements(la) && rotate_elements(lb));
}

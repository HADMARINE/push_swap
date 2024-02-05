/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:21:28 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/05 15:22:59 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_elements(t_list **dest, t_list **src)
{
	t_list	*lp;

	if (*src == NULL)
		return (false);
	lp = *src;
	*src = (*src)->next;
	lp->next = *dest;
	*dest = lp;
	return (true);
}

bool	push_a(t_list **la, t_list **lb)
{
	ft_putstr_fd("pa\n", 1);
	return (push_elements(la, lb));
}

bool	push_b(t_list **la, t_list **lb)
{
	ft_putstr_fd("pb\n", 1);
	return (push_elements(lb, la));
}

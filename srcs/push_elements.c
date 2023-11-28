/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:21:28 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:34:38 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_elements(t_list **dest, t_list **src)
{
	t_list	*lp;

	lp = *src;
	*src = (*src)->next;
	lp->next = *dest;
	*dest = lp;
}

bool	push_a(t_list **la, t_list **lb)
{
	ft_putstr_fd("pa\n", 1);
	return (push_elements(la, lb));
}

bool	push_b(t_list **la, t_list **lb)
{
	ft_putstr_fd("pa\n", 1);
	return (push_elements(lb, la));
}
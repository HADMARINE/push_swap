/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:13:34 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:31:45 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap_elements(t_list **lst)
{
	void	*ep;

	if (!lst || !*lst || !(*lst)->next)
		return (false);
	ep = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = ep;
	return (true);
}

bool	swap_a(t_list **la)
{
	ft_putstr_fd("sa\n", 1);
	return (swap_elements(la));
}

bool	swap_b(t_list **lb)
{
	ft_putstr_fd("sb\n", 1);
	return (swap_elements(lb));
}

bool	swap_all(t_list **la, t_list **lb)
{
	ft_putstr_fd("ss\n", 1);
	return (swap_elements(la) && swap_elements(lb));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:55:52 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/29 18:06:09 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_list **lst, t_stack_type stack)
{
	
}

t_ab_value	get_move_cost(t_list *ta, t_list *tb, t_list *tbp)
{
	t_ab_value	v;
	t_list		*tap;

	v.a = 0;
	v.b = 0;
	v.b = tbp - tb;
	tap = ta;
	while (tap)
	{
		if (*((int *)tbp->content) < *((int *)tap->content))
		{
			v.a = tap - ta;
			return (v);
		}
		tap = tap->next;
	}
	tbp = tbp->next;
	v.a = 0;
	v.b = 0;
	return (v);
}

t_ab_value	get_smallest_cost(t_list **ta, t_list **tb)
{
	t_ab_value	abv;
	t_ab_value	abvp;
	t_list		*tbp;

	abv.a = 0;
	abv.b = 0;
	tbp = *tb;
	while (tbp)
	{
		abvp = get_move_cost(*ta, *tb, tbp);
		if (ft_absi(abvp.a) + ft_absi(abvp.b) < ft_absi(abv.a) + ft_absi(abv.b)
			|| (abv.a == 0 && abv.b == 0))
		{
			abv = abvp;
		}
		tbp = tbp->next;
	}
	return (abv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:55:52 by lhojoon           #+#    #+#             */
/*   Updated: 2023/12/01 12:41:08 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index_of_list(t_list *lp, t_list *lsp);

t_ab_value	get_move_cost(t_list *ta, t_list *tb, t_list *tbp)
{
	t_ab_value	v;
	t_list		*tap;

	v.a = 0;
	v.b = get_index_of_list(tb, tbp);
	if (v.b > ft_lstsize(tb) / 2)
		v.b = -(ft_lstsize(tb) - v.b);
	tap = ta;
	while (tap)
	{
		if (*((int *)tbp->content) < *((int *)tap->content))
		{
			v.a = get_index_of_list(ta, tap);
			if (v.a > ft_lstsize(ta) / 2)
				v.a = -(ft_lstsize(ta) - v.a);
			return (v);
		}
		if (tap->next == NULL)
		{
			v.a = get_index_of_list(ta, tap) + 1;
			return (v);
		}
		tap = tap->next;
	}
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
		if (ft_absi(abvp.a) * 2 + ft_absi(abvp.b)
			< ft_absi(abv.a) * 2 + ft_absi(abv.b)
			|| (abv.a == 0 && abv.b == 0))
		{
			abv = abvp;
		}
		tbp = tbp->next;
	}
	return (abv);
}

static void	execute_value_b(t_ab_value value, t_list **tb)
{
	if (value.b < 0)
	{
		value.b = -value.b;
		while (value.b-- != 0)
			reverse_rotate_b(tb);
	}
	else
	{
		while (value.b-- != 0)
			rotate_b(tb);
	}
}

static void	execute_value_a(t_ab_value value, t_list **ta, t_list **tb)
{
	int	avalue;

	avalue = value.a;
	if (value.a < 0)
	{
		value.a = -value.a;
		while (value.a-- != 0)
			reverse_rotate_a(ta);
	}
	else
	{
		if (value.a != ft_lstsize(*ta))
			while (value.a-- != 0)
				rotate_a(ta);
	}
	push_a(ta, tb);
	if (avalue < 0)
	{
		avalue = -avalue + 1;
		while (avalue-- != 0)
			rotate_a(ta);
	}
	else
	{
		if (avalue == ft_lstsize(*ta))
			rotate_a(ta);
		else
			while (avalue-- != 0)
				reverse_rotate_a(ta);
	}
}

void	execute_by_command(t_ab_value value, t_list **ta, t_list **tb)
{
	execute_value_b(value, tb);
	execute_value_a(value, ta, tb);
}

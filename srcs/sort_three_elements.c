/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:57:01 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/29 22:35:55 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_stt(t_list **lst, t_stack_type stack);

static void	s_rr_stt(t_list **lst, t_stack_type stack)
{
	if (stack == STACK_TYPE_A)
	{
		swap_a(lst);
		reverse_rotate_a(lst);
	}
	else
	{
		swap_b(lst);
		reverse_rotate_b(lst);
	}
}

static void	r_stt(t_list **lst, t_stack_type stack)
{
	if (stack == STACK_TYPE_A)
		rotate_a(lst);
	else
		rotate_b(lst);
}

static void	s_stt(t_list **lst, t_stack_type stack)
{
	if (stack == STACK_TYPE_A)
		swap_a(lst);
	else
		swap_b(lst);
}

static void	s_r_stt(t_list **lst, t_stack_type stack)
{
	if (stack == STACK_TYPE_A)
	{
		swap_a(lst);
		rotate_a(lst);
	}
	else
	{
		swap_b(lst);
		rotate_b(lst);
	}
}

void	sort_three_elements(t_list **lst, t_stack_type stack)
{
	if (verify_sorted(*lst) == true)
		return ;
	if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content)
	&& *((int *)(*lst)->next->content) > *((int *)(*lst)->next->next->content))
		return (s_rr_stt(lst, stack));
	if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content)
	&& *((int *)(*lst)->next->content) < *((int *)(*lst)->next->next->content))
	{
		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->next->content))
			return (r_stt(lst, stack));
		else
			return (s_stt(lst, stack));
	}
	if (*((int *)(*lst)->content) < *((int *)(*lst)->next->content)
	&& *((int *)(*lst)->next->content) > *((int *)(*lst)->next->next->content))
	{
		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->next->content))
			return (rr_stt(lst, stack));
		else
			return (s_r_stt(lst, stack));
	}
}

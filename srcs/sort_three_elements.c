/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:57:01 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/06 15:19:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rr_stt(t_list **lst, t_stack_type stack);

// static void	s_rr_stt(t_list **lst, t_stack_type stack)
// {
// 	if (stack == STACK_TYPE_A)
// 	{
// 		swap_a(lst);
// 		reverse_rotate_a(lst);
// 	}
// 	else
// 	{
// 		swap_b(lst);
// 		reverse_rotate_b(lst);
// 	}
// }

// static void	r_stt(t_list **lst, t_stack_type stack)
// {
// 	if (stack == STACK_TYPE_A)
// 		rotate_a(lst);
// 	else
// 		rotate_b(lst);
// }

// static void	s_stt(t_list **lst, t_stack_type stack)
// {
// 	if (stack == STACK_TYPE_A)
// 		swap_a(lst);
// 	else
// 		swap_b(lst);
// }

// static void	s_r_stt(t_list **lst, t_stack_type stack)
// {
// 	if (stack == STACK_TYPE_A)
// 	{
// 		swap_a(lst);
// 		rotate_a(lst);
// 	}
// 	else
// 	{
// 		swap_b(lst);
// 		rotate_b(lst);
// 	}
// }

// void	sort_three_elements(t_list **lst, t_stack_type stack)
// {
// 	if (verify_sorted(*lst) == true)
// 		return ;
// 	if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content)
// 	&& *((int *)(*lst)->next->content) > *((int *)(*lst)->next->next->content))
// 		return (s_rr_stt(lst, stack));
// 	if (*((int *)(*lst)->content) > *((int *)(*lst)->next->content)
// 	&& *((int *)(*lst)->next->content) < *((int *)(*lst)->next->next->content))
// 	{
// 		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->next->content))
// 			return (r_stt(lst, stack));
// 		else
// 			return (s_stt(lst, stack));
// 	}
// 	if (*((int *)(*lst)->content) < *((int *)(*lst)->next->content)
// 	&& *((int *)(*lst)->next->content) > *((int *)(*lst)->next->next->content))
// 	{
// 		if (*((int *)(*lst)->content) > *((int *)(*lst)->next->next->content))
// 			return (rr_stt(lst, stack));
// 		else
// 			return (s_r_stt(lst, stack));
// 	}
// }

int	ft_lstposintmin(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		ret;

	tmp = (*stack);
	min = *(int *)((*stack)->content);
	i = 0;
	ret = 0;
	while (tmp)
	{
		if (*(int *)(tmp->content) < min)
		{
			min = *(int *)(tmp->content);
			ret = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

void	move_min(t_list **stack, int pos)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack);
	if (stack_size / 2 > pos)
	{
		while (pos--)
			rotate_a(stack);
	}
	else
	{
		pos = stack_size - pos;
		while (pos--)
			reverse_rotate_a(stack);
	}
}

void	sort_three_elements(t_list **lst)
{
	int	top;
	int	middle;
	int	bottom;

	top = *(int *)((*lst)->content);
	middle = *(int *)(((*lst)->next)->content);
	bottom = *(int *)((((*lst)->next)->next)->content);
	if (top > middle && middle < bottom && top < bottom)
		swap_a(lst);
	else if (top > middle && middle > bottom)
	{
		swap_a(lst);
		reverse_rotate_a(lst);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(lst);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_a(lst);
		rotate_a(lst);
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate_a(lst);
}

void	sort_four_elements(t_list **la, t_list **lb)
{
	move_min(la, ft_lstposintmin(la));
	push_b(la, lb);
	sort_three_elements(la);
	push_a(la, lb);
}

void	sort_five_elements(t_list **la, t_list **lb)
{
	move_min(la, ft_lstposintmin(la));
	push_b(la, lb);
	move_min(la, ft_lstposintmin(la));
	push_b(la, lb);
	sort_three_elements(la);
	push_a(la, lb);
	push_a(la, lb);
}

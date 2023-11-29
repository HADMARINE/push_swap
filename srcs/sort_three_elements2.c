/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:11:45 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/29 22:12:50 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_stt(t_list **lst, t_stack_type stack)
{
	if (stack == STACK_TYPE_A)
		reverse_rotate_a(lst);
	else
		reverse_rotate_b(lst);
}

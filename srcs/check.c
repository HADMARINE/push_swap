/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:51:11 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:25:02 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	verify_sorted(t_list *lst)
{
	int	value;

	value = *((int *)lst->content);
	lst = lst->next;
	while (lst)
	{
		if (value > *(int *)lst->content)
			return (false);
		value = *(int *)lst->content;
		lst = lst->next;
	}
	return (true);
}

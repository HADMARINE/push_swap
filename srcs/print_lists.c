/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:57:44 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/29 23:00:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_list *la, t_list *lb)
{
	t_list	*lp;

	lp = la;
	ft_printf("A : ");
	while (lp)
	{
		ft_printf("%d ", *((int *)lp->content));
		lp = lp->next;
	}
	ft_printf("\nB : ");
	lp = lb;
	while (lp)
	{
		ft_printf("%d ", *((int *)lp->content));
		lp = lp->next;
	}
	ft_putchar_fd('\n', 1);
}

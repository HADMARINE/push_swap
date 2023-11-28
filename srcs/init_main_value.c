/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:00:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 16:12:33 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init_main_value(int argc, char *argv[], t_list **la)
{
	int		i;
	t_list	*lp;

	i = 0;
	while (i < argc)
	{
		lp = ft_lstnew(argv[i]);
		if (!lp)
		{
			ft_lstclear(la, NULL);
			return (false);
		}
		push_stack(la, lp);
		i++;
	}
	return (true);
}

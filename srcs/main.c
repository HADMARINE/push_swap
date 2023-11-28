/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:14:57 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:42:47 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*la;
	t_list	*lb;
	int		i;

	if (init_main_value(argc, argv, &la) == false)
		return (EXIT_FAILURE);
	execution(&la, &lb);
	while (la)
	{
		ft_printf("%d")
	}
	return (EXIT_SUCCESS);
}

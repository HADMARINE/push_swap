/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:14:57 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/29 23:01:05 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*la;
	t_list	*lb;
	char	**slst;
	int		lstlen;

	if (argc <= 1)
		return (EXIT_FAILURE);
	if (argc == 2)
		init_params_split(argv[1], &slst, &lstlen);
	else
		init_params_plain(argc, argv, &slst, &lstlen);
	la = NULL;
	lb = NULL;
	if (init_main_value(slst, lstlen, &la) == false)
		return (EXIT_FAILURE);
	execution(&la, &lb);
	ft_lstclear(&la, free);
	return (EXIT_SUCCESS);
}

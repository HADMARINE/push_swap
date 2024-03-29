/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:14:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/24 00:10:48 by lhojoon          ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	if (argc == 2)
		init_params_split(argv[1], &slst, &lstlen);
	else
		init_params_plain(argc, argv, &slst, &lstlen);
	if (input_error_check(slst, lstlen) == false)
		exit_with_error();
	la = NULL;
	lb = NULL;
	if (init_main_value(slst, lstlen, &la) == false)
		exit_with_error();
	if (duplicate_check(la) == false)
	{
		ft_lstclear(&la, free);
		exit_with_error();
	}
	execution(&la, &lb);
	ft_lstclear(&la, free);
	return (EXIT_SUCCESS);
}

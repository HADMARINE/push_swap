/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:33:05 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/23 23:57:57 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_slst(char **slst, int lstlen)
{
	int	i;

	i = 0;
	while (i < lstlen)
	{
		free(slst[i]);
		i++;
	}
	free(slst);
}

bool	error_free_and_exit(char **slst, int lstlen)
{
	free_slst(slst, lstlen);
	return (false);
}

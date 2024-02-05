/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:52:00 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/05 19:54:28 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(void)
{
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

static void	free_slst(char **slst, int lstlen)
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

bool	input_error_check(char **slst, int lstlen, bool is_freeable)
{
	if (lstlen == 0)
	{
		if (is_freeable == true)
			free_slst(slst, lstlen);
		return (false);
	}
	return (true);
}
//
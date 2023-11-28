/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:00:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 22:13:52 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static char	**get_value_of_arrays(int *argc, char *argv[])
// {
// 	int		i;
// 	char	**v;

// 	i = 1;
// 	v = NULL;
// 	while (i < *argc)
// 	{
// 		v = (char **)malloc(sizeof(char *) * (*argc - 1));
// 		v[i - 1] = argv[i];
// 		i++;
// 	}
// 	*argc = i - 1;
// 	return (v);
// }

int	init_params_split(char *str, char ***slst, int *lstlen)
{
	char	**sp;

	*slst = ft_split(str, ' ');
	if (!*slst)
		return (-1);
	sp = *slst;
	while (*sp != NULL)
		sp += 1;
	*lstlen = (int)(sp - *slst);
	return (0);
}

int	init_params_plain(int argc, char **argv, char ***slst, int *lstlen)
{
	int	i;

	*slst = (char **)malloc(sizeof(char *) * (argc - 1));
	if (!*slst)
		return (-1);
	i = 1;
	while (i < argc)
	{
		((*slst)[i - 1])
			= (char *)malloc((ft_strlen(argv[i] + 1) * sizeof(char)));
		ft_strlcpy((*slst)[i - 1], argv[i], ft_strlen(argv[i]) + 1);
		i++;
	}
	*lstlen = i - 1;
	return (0);
}

bool	init_main_value(char **slst, int lstlen, t_list **la)
{
	int		*ip;
	t_list	*lp;

	while (lstlen-- != 0)
	{
		ip = (int *)malloc(sizeof(int));
		*ip = ft_atoi(slst[lstlen]);
		free(slst[lstlen]);
		lp = ft_lstnew(ip);
		if (!lp)
		{
			ft_lstclear(la, NULL);
			return (false);
		}
		push_stack(la, lp);
	}
	free(slst);
	return (true);
}

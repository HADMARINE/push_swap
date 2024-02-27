/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:32:52 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/27 19:40:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
	return (new);
}

t_list	*ft_int_deep_lstcpy(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;
	int		*content;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			return (ft_lstclear(&new, free), NULL);
		*content = *((int *)tmp->content);
		ft_lstadd_back(&new, ft_lstnew(content));
		tmp = tmp->next;
	}
	return (new);
}

void	ft_lstswap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

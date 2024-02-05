/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:03 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/05 18:48:07 by lhojoon          ###   ########.fr       */
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

void	ft_lstswap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

t_list	*sort_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*new;
	int		i;
	int		j;

	i = 0;
	new = ft_lstcpy(lst);
	while (i < ft_lstsize(lst) - 1)
	{
		j = i;
		tmp = ft_lstget_idx(new, i);
		while (j < ft_lstsize(lst) - 1)
		{
			if (*((int *)tmp->content) > *((int *)tmp->next->content))
			{
				ft_lstswap(tmp, tmp->next);
			}
			tmp = tmp->next;
			j++;
		}
		i++;
	}
	return (new);
}

void	lst_paste(t_list *dest, t_list *src)
{
	while (src)
	{
		*((int *)dest->content) = *((int *)src->content);
		dest = dest->next;
		src = src->next;
	}
}

void	replace_by_simple_number(t_list **la)
{
	t_list	*tmp;
	t_list	*new;
	int		i;
	int		j;

	i = -1;
	tmp = sort_lst(*la);
	new = ft_lstcpy(*la);
	while (++i < ft_lstsize(*la))
	{
		j = 0;
		while (j < ft_lstsize(*la))
		{
			if (*((int *)ft_lstget_idx(tmp, i)->content)
				== *((int *)ft_lstget_idx(*la, j)->content))
			{
				*((int *)ft_lstget_idx(new, j)->content) = i;
				break ;
			}
			j++;
		}
	}
	lst_paste(*la, new);
	ft_lstclear(&tmp, NULL);
	ft_lstclear(&new, NULL);
}

void	execution(t_list **la, t_list **lb)
{
	int		size;
	int		i;
	int		j;

	replace_by_simple_number(la);
	size = ft_lstsize(*la);
	i = 0;
	while (!verify_sorted(*la))
	{
		j = 0;
		while (size > j)
		{
			if (((*((int *)(*la)->content) >> i) & 1) == 1)
				rotate_a(la);
			else
				push_b(la, lb);
			j++;
		}
		while (*lb != NULL)
		{
			push_a(la, lb);
		}
		i++;
	}	
}

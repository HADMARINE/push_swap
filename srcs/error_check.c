/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:52:00 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/24 00:08:46 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	input_numbers_check_start(char *s, int *j, int *zero_count)
{
	*j = 0;
	*zero_count = 0;
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*(s + 1) == '\0')
			return (false);
		*j += 1;
	}
	return (true);
}

static bool	int_range_check(char *s)
{
	bool	is_minus;

	is_minus = false;
	while (*s == ' ')
		s++;
	if (*s == '-')
	{
		is_minus = true;
		s++;
	}
	if (*s == '+')
		s++;
	while (*s == '0')
		s++;
	if (ft_strlen(s) > 10)
		return (false);
	if (ft_strlen(s) < 10)
		return (true);
	if (is_minus && ft_strncmp(s, "2147483648", 10) > 0)
		return (false);
	if (!is_minus && ft_strncmp(s, "2147483647", 10) > 0)
		return (false);
	return (true);
}

static bool	input_numbers_check(char **s, int lstlen)
{
	int		i;
	int		j;
	char	*str;
	int		zero_count;

	i = 0;
	while (i < lstlen)
	{
		str = s[i];
		input_numbers_check_start(str, &j, &zero_count);
		while (str[j])
		{
			if (ft_isdigit(str[j]) == 0)
				return (false);
			if (str[j] == '0')
				zero_count++;
			j++;
		}
		if (zero_count == (int)ft_strlen(str) && zero_count != 1)
			return (false);
		if (int_range_check(str) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	input_error_check(char **slst, int lstlen)
{
	if (lstlen == 0 || !input_numbers_check(slst, lstlen))
		return (error_free_and_exit(slst, lstlen));
	return (true);
}

bool	duplicate_check(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (*(int *)tmp->content == *(int *)tmp2->content)
				return (false);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (true);
}

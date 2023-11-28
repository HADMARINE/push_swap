/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:37:20 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 17:42:02 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

# include "libft.h"

bool	init_main_value(int argc, char *argv[], t_list **la);
bool	swap_elements(t_list **lst);
bool	swap_a(t_list **la);
bool	swap_b(t_list **lb);
bool	swap_all(t_list **la, t_list **lb);
bool	rotate_elements(t_list **lst);
bool	rotate_a(t_list **la);
bool	rotate_b(t_list **lb);
bool	rotate_all(t_list **la, t_list **lb);
bool	reverse_rotate_elements(t_list **lst);
bool	reverse_rotate_a(t_list **la);
bool	reverse_rotate_b(t_list **lb);
bool	reverse_rotate_all(t_list **la, t_list **lb);
bool	push_elements(t_list **dest, t_list **src);
bool	push_a(t_list **la, t_list **lb);
bool	push_b(t_list **la, t_list **lb);
bool	verify_sorted(t_list *lst);
void	execution(t_list **la, t_list **lb);

#endif
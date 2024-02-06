/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:37:20 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/06 12:48:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "libft.h"

typedef enum e_stack_type {
	STACK_TYPE_A = 0,
	STACK_TYPE_B = 1
}	t_stack_type;

typedef struct s_ab_value {
	int	a;
	int	b;
}	t_ab_value;

bool		init_main_value(char **slst, int lstlen, t_list **la);
int			init_params_plain(int argc, char **argv, char ***slst, int *lstlen);
int			init_params_split(char *str, char ***slst, int *lstlen);
bool		swap_elements(t_list **lst);
bool		swap_a(t_list **la);
bool		swap_b(t_list **lb);
bool		swap_all(t_list **la, t_list **lb);
bool		rotate_elements(t_list **lst);
bool		rotate_a(t_list **la);
bool		rotate_b(t_list **lb);
bool		rotate_all(t_list **la, t_list **lb);
bool		reverse_rotate_elements(t_list **lst);
bool		reverse_rotate_a(t_list **la);
bool		reverse_rotate_b(t_list **lb);
bool		reverse_rotate_all(t_list **la, t_list **lb);
bool		push_elements(t_list **dest, t_list **src);
bool		push_a(t_list **la, t_list **lb);
bool		push_b(t_list **la, t_list **lb);
bool		verify_sorted(t_list *lst);
void		execution(t_list **la, t_list **lb);
void		sort_three_elements(t_list **lst, t_stack_type stack);
t_ab_value	get_smallest_cost(t_list **ta, t_list **tb);
void		execute_by_command(t_ab_value value, t_list **ta, t_list **tb);
void		print_lists(t_list *la, t_list *lb);
bool		input_error_check(char **slst, int lstlen, bool is_freeable);
void		exit_with_error(void);
void		free_slst(char **slst, int lstlen);
bool		error_free_and_exit(char **slst, int lstlen, bool is_freeable);
bool		duplicate_check(t_list *lst);

#endif
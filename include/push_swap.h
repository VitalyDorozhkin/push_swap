/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:16:53 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/13 21:01:35 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

void	sa(t_list *a, int f);
void	sb(t_list *b, int f);
void	ss(t_list *a, t_list *b, int f);
void	pa(t_list **a, t_list **b, int f);
void	pb(t_list **a, t_list **b, int f);
void	ra(t_list **a, int f);
void	rb(t_list **b, int f);
void	rr(t_list **a, t_list **b, int f);
void	rra(t_list **a, int f);
void	rrb(t_list **b, int f);
void	rrr(t_list **a, t_list **b, int f);

t_list	*set_list(int argc, char **argv);
int		get_max_len(t_list *lst);
void	ft_print_border(int c, int flag, char *comand);
void	print_list(t_list *lst_a, t_list *lst_b, int c, char *comand);
void	print_message(char *str);
int		max(int a, int b);
void	is_dub(t_list *lst_a);
void	is_sort(t_list *lst_a);
void	is_small(t_list **lst_a);

void	sort_three(t_list **lst_a);
void	roll(t_list **lst);
void	go_together(t_list **lst_a, t_list **lst_b, int i, int c);
void	go_self(t_list **lst_a, t_list **lst_b, int i, int c);
void	push_back(t_list **lst_a, t_list **lst_b);

int		opti(int i, t_list *lst_b);
int		count_ops(int c, t_list *lst_a);
int		minin(int i, int c, t_list *lst_a, t_list *lst_b);
int		find(t_list *lst_a, t_list *lst_b, int *res);
int		mid(t_list *lst);

int		get_max_len(t_list *lst);

void	read_flags_v(int *argc, char ***argv, int *c);
void	read_flags_f(int *argc, char ***argv);

#endif

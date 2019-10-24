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

void sa(t_list *a, int f);
void sb(t_list *b, int f);
void ss(t_list *a, t_list *b, int f);
void pa(t_list **a, t_list **b, int f);
void pb(t_list **a, t_list **b, int f);
void ra(t_list **a, int f);
void rb(t_list **b, int f);
void rr(t_list **a, t_list **b, int f);
void rra(t_list **a, int f);
void rrb(t_list **b, int f);
void rrr(t_list **a, t_list **b, int f);
#endif
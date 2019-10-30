/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_list **a, int f)
{
	t_list *tmp;
	t_list *tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp2 = *a;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	if (f)
		ft_printf("ra\n");
}

void	rb(t_list **b, int f)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp2 = *b;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	if (f)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, int f)
{
	if (a && *b)
		ra(a, 0);
	if (b && *b)
		rb(b, 0);
	if (f)
		ft_printf("rr\n");
}

void	rra(t_list **a, int f)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (a && *a)
	{
		tmp = *a;
		if ((*a)->next)
		{
			while (tmp->next->next)
				tmp = tmp->next;
			tmp2 = tmp->next;
			tmp->next = NULL;
			tmp2->next = *a;
			*a = tmp2;
		}
		else
			sb(*a, 0);
		if (f)
			ft_printf("rra\n");
	}
}

void	rrb(t_list **b, int f)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (b && *b)
	{
		tmp = *b;
		if ((*b)->next)
		{
			while (tmp->next->next)
				tmp = tmp->next;
			tmp2 = tmp->next;
			tmp->next = NULL;
			tmp2->next = *b;
			*b = tmp2;
		}
		else
			sb(*b, 0);
		if (f)
			ft_printf("rrb\n");
	}
}

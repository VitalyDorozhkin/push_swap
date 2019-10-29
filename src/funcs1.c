/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void sa(t_list *a, int f)
{
	if(a && (a)->next)
	{
		int tmp;

		tmp = a->content_size;
		a->content_size = a->next->content_size;
		a->next->content_size = tmp;
	}
	if (f)
		ft_printf("sa\n");
}

void sb(t_list *b, int f)
{
	if(b && (b)->next)
	{		
		int tmp;

		tmp = b->content_size;
		b->content_size = b->next->content_size;
		b->next->content_size = tmp;
	}
	if (f)
		ft_printf("sb\n");
}

void ss(t_list *a, t_list *b, int f)
{
	sa(a, 0);
	sb(b, 0);
	if (f)
		ft_printf("ss\n");
}

void pa(t_list **a, t_list **b, int f)
{
	t_list *tmp;
	if(*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	if (f)
		ft_printf("pa\n");
	
}

void pb(t_list **a, t_list **b, int f)
{
	t_list *tmp;
	if(*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	if (f)
		ft_printf("pb\n");
}

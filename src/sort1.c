/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_list **lst_a)
{
	int	a;
	int	b;
	int	c;

	a = (*lst_a)->content_size;
	b = (*lst_a)->next->content_size;
	c = (*lst_a)->next->next->content_size;
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		sa(*lst_a, 1);
}

void	roll(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp && tmp->next && tmp->content_size < tmp->next->content_size)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_lstlen(*lst) - i - 1)
		while ((*lst)->content_size > ft_lstlast(*lst))
			ra(lst, 1);
	else
		while ((*lst)->content_size > ft_lstlast(*lst))
			rra(lst, 1);
}

void	go_together(t_list **lst_a, t_list **lst_b, int i, int c)
{
	if (i >= 0 && c >= 0)
	{
		while (i && c && --i + 1 && --c + 1)
			rr(lst_a, lst_b, 1);
		while (i-- > 0)
			rb(lst_b, 1);
		while (c-- > 0)
			ra(lst_a, 1);
	}
	else
	{
		while (i && c && ++i - 1 && ++c - 1)
			rrr(lst_a, lst_b, 1);
		while (i++ < 0)
			rrb(lst_b, 1);
		while (c++ < 0)
			rra(lst_a, 1);
	}
}

void	go_self(t_list **lst_a, t_list **lst_b, int i, int c)
{
	if (i >= 0)
		while (i--)
			rb(lst_b, 1);
	else
		while (i++)
			rrb(lst_b, 1);
	if (c >= 0)
		while (c--)
			ra(lst_a, 1);
	else
		while (c++)
			rra(lst_a, 1);
}

void	push_back(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	c;
	int	g;

	while (*lst_b)
	{
		i = find(*lst_a, *lst_b, &g);
		c = count_ops(g, *lst_a);
		if (i * c < 0)
		{
			if (i < 0 && i + c > max(ft_lstlen(*lst_b) + i, c))
				i = ft_lstlen(*lst_b) + i;
			else if (c < 0 && i + c > max(ft_lstlen(*lst_a) + c, i))
				c = ft_lstlen(*lst_a) + c;
		}
		if (i * c <= 0)
			go_self(lst_a, lst_b, i, c);
		else
			go_together(lst_a, lst_b, i, c);
		pa(lst_a, lst_b, 1);
	}
}

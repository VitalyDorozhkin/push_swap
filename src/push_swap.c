/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void sort_three(t_list **lst_a)
{
	int	a;
	int	b;
	int	c;

	a = (*lst_a)->content_size;
	b = (*lst_a)->next->content_size;
	c = (*lst_a)->next->next->content_size;
	if((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		sa(*lst_a, 1);
}

int count_ops(int c, t_list *lst_a)
{
	t_list	*tmp_a;
	int		i;
	int		j;

	tmp_a = lst_a;
	i = 0;
	j = ft_lstlen(lst_a);
	if (tmp_a->content_size > c)
	{
	    while (tmp_a->next && tmp_a->content_size < tmp_a->next->content_size)
	        tmp_a = tmp_a->next;
	    tmp_a = tmp_a->next;
	    while (tmp_a && tmp_a->content_size < c)
	        tmp_a = tmp_a->next;
	    while (tmp_a && ++i)
	        tmp_a = tmp_a->next;
	    return (-i);
	}
	while (tmp_a && tmp_a->content_size <= c && ++i)
	    tmp_a = tmp_a->next;
	return (i);
}

int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

int minin(int i, int c, t_list *lst_a, t_list *lst_b)
{
	int	lena;
	int	lenb;

	lena = ft_lstlen(lst_a);
	lenb = ft_lstlen(lst_b);
	i = opti(i, lst_b);
	if (i * c < 0)
	{
		if (i < 0)
			i += (i + c > max(lenb + i, c)) ? lenb : 0;
		else
			c += (i + c > max(lena + c, i)) ? lena : 0;
    }
    if (i * c >= 0)
    	return (max(i, c));
    return (i + c);
}

int opti(int i, t_list *lst_b)
{
	int	lenb;

	lenb = ft_lstlen(lst_b);
	if (i < lenb - i)
		return (i);
	else
		return (-1 * (lenb - i));
}

int find(t_list *lst_a, t_list *lst_b, int *res)
{
	int		i;
	int		min;
	int		mini;
	int		j;
	t_list	*tmp_b;

	j = ft_lstlen(lst_b);
	i = 0;
	min = 2147483647;
	tmp_b = lst_b;
	while (tmp_b)
	{
		if ((i < min || j - i < min) && (minin(i, count_ops(tmp_b->content_size,
			lst_a), lst_a, lst_b) + tmp_b->content_size <= min + *res))
		{
			*res = tmp_b->content_size;
			min = minin(i, count_ops(tmp_b->content_size, lst_a), lst_a, lst_b);
			mini = i;
		}
		tmp_b = tmp_b->next;
		i++;
	}
	return ((mini < j - mini) ? mini : -1 * (j - mini));
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

void push_back(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	c;
	int	g;

	while(*lst_b)
	{
		i = find(*lst_a, *lst_b, &g);
		c = count_ops(g, *lst_a);
		if (i * c < 0)
			if (i < 0 && i + c > max(ft_lstlen(*lst_b) + i, c))
				i = ft_lstlen(*lst_b) + i;
			else if (c < 0 && i + c > max(ft_lstlen(*lst_a) + c, i))
				c = ft_lstlen(*lst_a) + c;
		if (i * c <= 0)
			go_self(lst_a, lst_b, i, c);
		else
			go_together(lst_a, lst_b, i, c);
		pa(lst_a, lst_b, 1);
	}
}

void roll(t_list **lst)
{
	t_list *tmp;
	int	i;

	tmp = *lst;
	i = 0;
	while (tmp && tmp->next && tmp->content_size < tmp->next->content_size)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_lstlen(*lst) - i)
		while((*lst)->content_size > ft_lstlast(*lst))
			ra(lst, 1);
	else
		while((*lst)->content_size > ft_lstlast(*lst))
			rra(lst, 1);
}

int mid(t_list *lst)
{
	int		low;
	int		up;
	t_list	*tmp1;
	t_list	*tmp2;

	low = ft_lstlen(lst);
	up = 0;
	tmp1 = lst;
	tmp2 = lst;
	while (tmp1 && low != up && low != up - 1)
	{
		low = 0;
		up = 0;
		tmp2 = lst;
		while (tmp2)
		{
			up += (tmp2->content_size >= tmp1->content_size);
			low += (tmp2->content_size < tmp1->content_size);
			tmp2 = tmp2->next;
		}
		if (low != up && low != up - 1)
			tmp1 = tmp1->next;
	}
	return (tmp1->content_size);
}

void	quick_sort(t_list **lst_a, t_list **lst_b)
{
	int midi;
	int lena;
	int i;

	while ((lena = ft_lstlen(*lst_a)) > 3)
	{
		midi = mid(*lst_a);
		i = 0;
		while (i < lena / 2 && lena - i > 3)
			if ((*lst_a)->content_size < midi && ++i)
			{
				pb(lst_a, lst_b, 1);
				if ((*lst_b)->content_size > mid(*lst_b))
				{
					if (i < lena / 2 && lena - i > 3 &&
						(*lst_a)->content_size >= midi)
						rr(lst_a, lst_b, 1);
					else
						rb(lst_b, 1);
				}
			}
			else
				ra(lst_a, 1);
	}
}

int		main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		c;

	lst_b = NULL;
	lst_a = set_list(argc, argv);
	c = get_max_len(lst_a);
	quick_sort(&lst_a, &lst_b);
	sort_three(&lst_a);
	push_back(&lst_a, &lst_b);
	roll(&lst_a);
	//print_list(lst_a, lst_b, 3);
}

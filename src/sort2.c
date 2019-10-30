/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		opti(int i, t_list *lst_b)
{
	int	lenb;

	lenb = ft_lstlen(lst_b);
	if (i < lenb - i)
		return (i);
	else
		return (-1 * (lenb - i));
}

int		count_ops(int c, t_list *lst_a)
{
	t_list	*tmp_a;
	int		i;
	int		j;

	tmp_a = lst_a;
	i = 0;
	j = ft_lstlen(lst_a);
	if ((int)(tmp_a->content_size) > c)
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

int		minin(int i, int c, t_list *lst_a, t_list *lst_b)
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

int		find(t_list *lst_a, t_list *lst_b, int *res)
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
			lst_a), lst_a, lst_b) - min <= *res - tmp_b->content_size))
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

int		mid(t_list *lst)
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

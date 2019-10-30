/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_message(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int		max(int a, int b)
{
	return ((a >= b) ? a : b);
}

void	is_dub(t_list *lst_a)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = lst_a;
	while (tmp1 && tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->content_size == tmp2->content_size)
				print_message("Error");
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	is_sort(t_list *lst_a)
{
	t_list	*tmp;

	tmp = lst_a;
	while (tmp && tmp->next)
	{
		if (tmp->content_size >= tmp->next->content_size)
			return ;
		tmp = tmp->next;
	}
	exit(0);
}

void	is_small(t_list **lst_a)
{
	if (ft_lstlen(*lst_a) > 3)
		return ;
	if (ft_lstlen(*lst_a) == 3)
	{
		sort_three(lst_a);
		roll(lst_a);
	}
	else if (ft_lstlen(*lst_a) == 2)
		sa(*lst_a, 1);
	exit(0);
}

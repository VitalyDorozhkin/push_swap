/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_max_len(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		c;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if ((c = ft_nbrlen(tmp->content_size)) > i)
			i = c;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_print_border(int c, int flag)
{
	int i;

	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? 'A' : '-');
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putstr("  ");
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? 'B' : '-');
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putchar('\n');
}



void	print_list(t_list *lst_a, t_list *lst_b, int c)
{
	t_list	*lst_a_tmp;
	t_list	*lst_b_tmp;
	int		a_len;
	int		b_len;

	a_len = ft_lstlen(lst_a);
	b_len = ft_lstlen(lst_b);
	lst_a_tmp = lst_a;
	lst_b_tmp = lst_b;
	c = (c % 2) ? c : c + 1;
	ft_print_border(c, 1);
	while (lst_a_tmp || lst_b_tmp)
	{
		if (lst_a_tmp && a_len >= b_len && (a_len-- || 1))
		{
			ft_printf("|%-*d|", c, lst_a_tmp->content_size);
			lst_a_tmp = lst_a_tmp->next;
		}
		else
			ft_printf("|%*s|", c, " ");
		ft_printf("  ");
		if (lst_b_tmp && a_len < b_len && (b_len-- || 1))
		{
			ft_printf("|%-*d|\n", c, lst_b_tmp->content_size);
			lst_b_tmp = lst_b_tmp->next;
		}
		else
			ft_printf("|%*s|\n", c, " ");
	}
	ft_print_border(c, 0);
}

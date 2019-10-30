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

char	ft_last_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i + 1])
		i++;
	return (str[i]);
}

void	ft_print_border(int c, int flag, char *cmd)
{
	int		i;
	char	a;
	char	b;

	a = (ft_last_char(cmd) == 'a' || ft_last_char(cmd) == 'r') ? 'A' : 'a';
	b = (ft_last_char(cmd) == 'b' || ft_last_char(cmd) == 'r') ? 'B' : 'b';
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? a : '-');
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putstr("  ");
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? b : '-');
	i = 0;
	while (i++ <= c / 2)
		ft_putchar('-');
	if (cmd)
		ft_printf(" %*s", 3, cmd);
	ft_putchar('\n');
}

void	print_element_a(t_list **lst_a_tmp, int *a_len, int *b_len, int c)
{
	if ((*lst_a_tmp) && (*a_len) >= (*b_len))
	{
		(*a_len)--;
		ft_printf("|%-*d|", c, (*lst_a_tmp)->content_size);
		(*lst_a_tmp) = (*lst_a_tmp)->next;
	}
	else
		ft_printf("|%*s|", c, " ");
}

void	print_element_b(t_list **lst_b_tmp, int *a_len, int *b_len, int c)
{
	if ((*lst_b_tmp) && (*a_len) > (*b_len))
	{
		(*a_len)--;
		ft_printf("|%-*d|", c, (*lst_b_tmp)->content_size);
		(*lst_b_tmp) = (*lst_b_tmp)->next;
	}
	else
		ft_printf("|%*s|", c, " ");
}

void	print_list(t_list *lst_a, t_list *lst_b, int c, char *comand)
{
	t_list	*lst_a_tmp;
	t_list	*lst_b_tmp;
	int		a_len;
	int		b_len;
	int		i;

	c = max(get_max_len(lst_a), get_max_len(lst_b));
	a_len = ft_lstlen(lst_a);
	b_len = ft_lstlen(lst_b);
	lst_a_tmp = lst_a;
	lst_b_tmp = lst_b;
	c = (c % 2) ? c : c + 1;
	ft_print_border(c, 1, comand);
	i = a_len + b_len - ((a_len > b_len) ? a_len : b_len);
	while (i--)
		ft_printf("|%*s|  |%*s|\n", c, " ", c, " ");
	while (lst_a_tmp || lst_b_tmp)
	{
		print_element_a(&lst_a_tmp, &a_len, &b_len, c);
		ft_printf("  ");
		print_element_b(&lst_b_tmp, &b_len, &a_len, c);
		ft_printf("\n");
	}
	ft_print_border(c, 0, 0);
}

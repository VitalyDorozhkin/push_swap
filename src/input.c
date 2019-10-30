/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			get_max_len(t_list *lst)
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

void		rrr(t_list **a, t_list **b, int f)
{
	if (a && *b)
		rra(a, 0);
	if (b && *b)
		rrb(b, 0);
	if (f)
		ft_printf("rrr\n");
}

static int	check_num(char *s, int *r)
{
	int		i;
	int		s1;
	char	*s2;
	int		f;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i] == '0' && s[i + 1])
		i++;
	if (s[0] == '-' && !ft_strcmp("2147483648", &(s[i])) && (*r = -2147483648))
		return (1);
	s1 = ft_atoi(&(s[i]));
	f = ft_strcmp(
		(s2 = ft_itoa(s1)), &s[i]);
	free(s2);
	*r = s1 * ((s[0] == '-') ? -1 : 1);
	return (!f);
}

void		set_el(char **str, t_list **lst_a_tmp)
{
	if (check_num(*str, &((*lst_a_tmp)->content_size)))
	{
		(*lst_a_tmp)->next = (t_list *)ft_memalloc(sizeof(*(*lst_a_tmp)));
		(*lst_a_tmp) = (*lst_a_tmp)->next;
	}
	else
		print_message("Error");
	free(*str);
}

t_list		*set_list(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_a_tmp;
	char	**tmp;
	int		i;
	int		j;

	lst_a = (t_list *)ft_memalloc(sizeof(*lst_a));
	lst_a_tmp = lst_a;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		tmp = ft_strsplit(argv[i], ' ');
		while (tmp[++j])
			set_el(&(tmp[j]), &lst_a_tmp);
		free(tmp);
	}
	free(lst_a_tmp);
	lst_a_tmp = lst_a;
	while (lst_a_tmp && lst_a_tmp->next && lst_a_tmp->next->next)
		lst_a_tmp = lst_a_tmp->next;
	lst_a_tmp->next = NULL;
	return (lst_a);
}

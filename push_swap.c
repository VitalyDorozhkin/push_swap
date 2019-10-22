#include <libft.h>

int gg_iter = 0;

void sa(t_list *a)
{
	if(a && (a)->next)
	{
		int tmp;

		tmp = a->content_size;
		a->content_size = a->next->content_size;
		a->next->content_size = tmp;
	}
	gg_iter++;
}

void sb(t_list *b)
{
	if(b && (b)->next)
	{		
		int tmp;

		tmp = b->content_size;
		b->content_size = b->next->content_size;
		b->next->content_size = tmp;
	}
	gg_iter++;
}

void ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	gg_iter++;
}


void pa(t_list **a, t_list **b)
{
	t_list *tmp;
	if(*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	gg_iter++;
}

void pb(t_list **a, t_list **b)
{
	t_list *tmp;
	if(*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	gg_iter++;
}

void ra(t_list **a)
{
	if(*a && (*a)->next)
	{
		t_list *tmp;
		t_list *tmp2;

		tmp = *a;
		*a = (*a)->next;
		tmp2 = *a;
		while(tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	gg_iter++;
}

void rb(t_list **b)
{
	if(*b && (*b)->next)
	{
		t_list *tmp;
		t_list *tmp2;

		tmp = *b;
		*b = (*b)->next;
		tmp2 = *b;
		while(tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	gg_iter++;
}

void rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	gg_iter++;
}

void rra(t_list **a)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *a;
	while(tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *a;
	*a = tmp2;
	gg_iter++;
}

void rrb(t_list **b)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *b;
	while(tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *b;
	*b = tmp2;
	gg_iter++;
}

void rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	gg_iter++;
}

int ft_lstlen(t_list *lst)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = lst;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}	
	return (i);
}

t_list	*set_list(int argc, char **argv)
{
	t_list	*lst_a = (t_list *)ft_memalloc(sizeof(*lst_a));
	t_list	*lst_a_tmp;
	int		t;
	char	**tmp;
	int		i;
	int		j;

	lst_a_tmp = lst_a;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		tmp = ft_strsplit(argv[i], ' ');
		while(tmp[++j])
		{
			if((t = ft_atoi(tmp[j])) || tmp[j][0] == '0')
			{	
				lst_a_tmp->content_size = t;
				lst_a_tmp->next = (t_list *)ft_memalloc(sizeof(*lst_a_tmp));
				lst_a_tmp = lst_a_tmp->next;
			}
			free(tmp[j]);
		}
		free(tmp);		
	}
	lst_a_tmp = lst_a;
	while(lst_a_tmp && lst_a_tmp->next && lst_a_tmp->next->next)
		lst_a_tmp = lst_a_tmp->next;
	lst_a_tmp->next = NULL;
	return (lst_a);
}

int get_max_len(t_list *lst)
{
	t_list *tmp;
	int i;
	int c;
	i = 0;
	tmp = lst;
	while(tmp)
	{
		if ((c = ft_nbrlen(tmp->content_size)) > i)
			i = c;
		tmp = tmp->next;
	}	
	return (i);
}

void ft_print_border(int c, int flag)
{
	int i = 0;
	while(i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? 'A' : '-');
	i = 0;
	while(i++ <= c / 2)
		ft_putchar('-');
	ft_putstr("  ");
	i = 0;
	while(i++ <= c / 2)
		ft_putchar('-');
	ft_putchar((flag) ? 'B' : '-');
	i = 0;
	while(i++ <= c / 2)
		ft_putchar('-');
	ft_putchar('\n');
}

void	print_list(t_list *lst_a, t_list *lst_b, int c)
{
	t_list	*lst_a_tmp;
	t_list	*lst_b_tmp;
	int a_len;
	int b_len;
	int i = 0;
	a_len = ft_lstlen(lst_a);
	b_len = ft_lstlen(lst_b);
	lst_a_tmp = lst_a;
	lst_b_tmp = lst_b;
	c = (c % 2) ? c : c + 1;
	
	ft_print_border(c, 1);


	while(lst_a_tmp || lst_b_tmp)
	{
		if(lst_a_tmp && a_len >= b_len)
		{
			a_len--;
			ft_printf("|%-*d|", c, lst_a_tmp->content_size);
			lst_a_tmp = lst_a_tmp->next;
		}
		else
			ft_printf("|%*s|", c, " ");
		ft_printf("  ");
		if(lst_b_tmp && a_len < b_len)
		{
			b_len--;
			ft_printf("|%-*d|\n", c, lst_b_tmp->content_size);
			lst_b_tmp = lst_b_tmp->next;
		}
		else
			ft_printf("|%*s|\n", c, " ");
	}
	ft_print_border(c, 0);
}

void sort_three(t_list **lst_a)
{
	int a;
	int b;
	int c;

	a = (*lst_a)->content_size;
	b = (*lst_a)->next->content_size;
	c = (*lst_a)->next->next->content_size;
	if(a < b && b < c)
		return ;
	if(a < b)
	{
		rra(lst_a);
		if(c > a)
			sa(*lst_a);
	}
	else
	{
		if(a < c || b > c)
			sa(*lst_a);
		if(a > c && a > b)
			(c > b) ? ra(lst_a) : rra(lst_a);
	}
	ra(lst_a);
}



void		start(t_list **lst_a, t_list **lst_b, int c)
{
	int		max;
	int		premax;
	int		min;
	t_list	*tmp;

	tmp = *lst_a;
	max = -2147483647;
	premax = -2147483648;
	min = 2147483647;
	while (tmp)
	{
		if ((int)tmp->content_size > max)
		{
			premax = max;
			max = (int)tmp->content_size;
		}
		else if((int)tmp->content_size > premax)
			premax = (int)tmp->content_size;
		if((int)tmp->content_size < min)
			min = (int)tmp->content_size;
		tmp = tmp->next;
	}
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != min)
		pb(lst_a, lst_b);
	ra(lst_a);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != min)
		pb(lst_a, lst_b);
	ra(lst_a);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != min)
		pb(lst_a, lst_b);
	ra(lst_a);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != min)
		pb(lst_a, lst_b);
	sort_three(lst_a);
}

int get_max_idx(t_list *lst_b)
{
	int		max;
	int		maxi;
	int		i;
	t_list	*tmp;

	i = 0;
	maxi = 0;
	max = -2147483648;
	tmp = lst_b;
	while(tmp)
	{
		if((int)tmp->content_size > max)
		{
			max = tmp->content_size;
			maxi = i;
		}
		i++;
		tmp = tmp->next;
	}
	if(maxi < i - maxi)
		return (maxi);
	else
		return (-1 * (i - maxi));
}

int get_min_idx(t_list *lst_b)
{
	int		min;
	int		mini;
	int		i;
	t_list	*tmp;

	i = 0;
	mini = 0;
	min = 2147483647;
	tmp = lst_b;
	while(tmp)
	{
		if((int)tmp->content_size < min)
		{
			min = tmp->content_size;
			mini = i;
		}
		i++;
		tmp = tmp->next;
	}
	if(mini < i - mini)
		return (mini);
	else
		return (-1 * (i - mini));
}

int	get_min(int a, int b)
{
	return ((ft_abs(a) <= ft_abs(b)) ? a : b);
}

void doo(t_list **lst_a, t_list **lst_b, int c)
{
	int i;
	int max;
	int min;
	int d;
	d = 0;
	while(*lst_b)
	{
		max = get_max_idx(*lst_b);
		min = get_min_idx(*lst_b);
		i = get_min(max, min);
		if(i > 0)
			while(i--)
				rb(lst_b);
		else if(i < 0)
			while(i++)
				rrb(lst_b);
		pa(lst_a, lst_b);
		if(get_min(max, min) == min && ++d)
			ra(lst_a);
		print_list(*lst_a, *lst_b, c);
	}
	while(d-- >= 0)
		rra(lst_a);

}

int		main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int c;

	lst_a = set_list(argc, argv);
	c = get_max_len(lst_a);
	print_list(lst_a, lst_b, c);
	start(&lst_a, &lst_b, c);
	print_list(lst_a, lst_b, c);
	doo(&lst_a, &lst_b, c);
	print_list(lst_a, lst_b, c);
	ft_printf("%d", gg_iter);
}

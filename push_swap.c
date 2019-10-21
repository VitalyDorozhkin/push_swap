#include <libft.h>

void sa(t_list *a)
{
	if(a && (a)->next)
	{
		int tmp;

		tmp = a->content_size;
		a->content_size = a->next->content_size;
		a->next->content_size = tmp;
	}
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
}

void ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
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
}

void rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
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
}

void rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
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
	sleep(1);
}

int		main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int c;
	t_list	*lst_a_tmp;
	lst_a = set_list(argc, argv);
	c = get_max_len(lst_a);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	ra(&lst_a);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	ra(&lst_a);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	ra(&lst_a);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pa(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pa(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	ra(&lst_a);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);
	pb(&lst_a, &lst_b);
	print_list(lst_b, lst_a, c);

}

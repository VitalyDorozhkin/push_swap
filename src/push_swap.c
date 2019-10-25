#include <push_swap.h>

void sort_three(t_list **lst_a)
{
	int a;
	int b;
	int c;

	a = (*lst_a)->content_size;
	b = (*lst_a)->next->content_size;
	c = (*lst_a)->next->next->content_size;
	if(a < b && b < c)
		;
	else if(a < b)
	{
		rra(lst_a, 1);
		if(c > a)
			sa(*lst_a, 1);
	}
	else
	{
		if(a < c || b > c)
			sa(*lst_a, 1);
		if(a > c && a > b)
			(c > b) ? ra(lst_a, 1) : rra(lst_a, 1);
	}
}


void sort_three2(t_list **lst_a)
{
	int a;
	int b;
	int c;

	a = (*lst_a)->content_size;
	b = (*lst_a)->next->content_size;
	c = (*lst_a)->next->next->content_size;
	if((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		sa(*lst_a, 1);
}

void		start(t_list **lst_a, t_list **lst_b, int c)
{
	int		max;
	int		premax;
	int		prepremax;

	max = get_max(*lst_a);
	premax = get_premax(*lst_a);
	prepremax = get_prepremax(*lst_a);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != prepremax)
		pb(lst_a, lst_b, 1);
	ra(lst_a, 1);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != prepremax)
		pb(lst_a, lst_b, 1);
	ra(lst_a, 1);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != prepremax)
		pb(lst_a, lst_b, 1);
	ra(lst_a, 1);
	while ((*lst_a)->content_size != max && (*lst_a)->content_size != premax && (*lst_a)->content_size != prepremax)
		pb(lst_a, lst_b, 1);
	sort_three2(lst_a);
}

int get_best(t_list *lst_a)
{
	int max = 0;
	int maxstart;
	int c;
	int prev;
	int i;

	t_list *tmp1 = lst_a;
	t_list *tmp2;
	while (tmp1)
	{
		tmp2 = tmp1;
		c = tmp2->content_size;
		tmp2 = tmp2->next;
		i = 0;
		while(tmp2)
		{
			if(tmp2->content_size > c)
			{
				c = tmp2->content_size;
				i++;
			}
			tmp2 = tmp2->next;
		}
		if(i > max)
		{
			maxstart = tmp1->content_size;
			max = i;
		}
		tmp1 = tmp1->next;
	}
	return (maxstart);
}

void		start2(t_list **lst_a, t_list **lst_b, int c)
{
	int		min;
	int		prev;

	min = get_best(*lst_a);
	prev = min;
	while((*lst_a)->content_size != min)
		pb(lst_a, lst_b, 1);
	ra(lst_a, 1);
	while ((*lst_a)->content_size != min)
	{
		if((*lst_a)->content_size > prev)
		{
			prev = (*lst_a)->content_size;
			ra(lst_a, 1);
		}
		else
			pb(lst_a, lst_b, 1);
	}
}

void		start3(t_list **lst_a, t_list **lst_b, int c)
{
	while ((*lst_a)->next->next->next)
		pb(lst_a, lst_b, 1);
	sort_three2(lst_a);
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


int get_min(t_list *lst_b)
{
	int		min;
	int		i;
	t_list	*tmp;

	i = 0;
	min = 2147483647;
	tmp = lst_b;
	while(tmp)
	{
		if((int)tmp->content_size < min)
			min = tmp->content_size;
		tmp = tmp->next;
	}
	return (min);
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


int count_ops(int c, t_list *lst_a)
{
    t_list  *tmp_a = lst_a;
    int    i = 0;
    int j = ft_lstlen(lst_a);

    if (tmp_a->content_size > c)
    {
        while(tmp_a->next && tmp_a->content_size < tmp_a->next->content_size)
            tmp_a = tmp_a->next;
        tmp_a = tmp_a->next;
        while(tmp_a && tmp_a->content_size < c)
            tmp_a = tmp_a->next;
        while(tmp_a)
        {
            tmp_a = tmp_a->next;
            i++;
        }
        return (-i);
    }
    while (tmp_a)
    {
        if (tmp_a->content_size > c)
            break ;
        tmp_a = tmp_a->next;
        i++;
    }
    return (i);
}

int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

int minin(int i, int c, t_list *lst_a, t_list *lst_b)
{
	int lena = ft_lstlen(lst_a);
	int lenb = ft_lstlen(lst_b);

	if (i * c < 0)
	{
		if(i < 0)
		{
			if(i + c > max(lenb + i, c))
				i = lenb + i;
		}
		else
		{
			if(i + c > max(lena + c, i))
				c = lena + c;
		}
    }
    if(i * c >= 0)
    	return (max(i, c));
    return (i + c);
}

int opti(int i, t_list *lst_b)
{
	int lenb = ft_lstlen(lst_b);
	if(i < lenb - i)
		return (i);
	else
		return (-1 * (lenb - i));
}
 
int find(t_list *lst_a, t_list *lst_b, int *res)
{
	int i = 0;
	int min = 2000000000;
	int mini = 0;
	t_list *tmp_a = lst_a;
	t_list *tmp_b = lst_b;
	int j = ft_lstlen(lst_b);
	while(tmp_b)
	{
		if((i < min || j - i < min) && minin(opti(i, lst_b), count_ops(tmp_b->content_size, lst_a), lst_a, lst_b) <= min)
		{
			if (minin(opti(i, lst_b), count_ops(tmp_b->content_size, lst_a), lst_a, lst_b) != min ||
				(*res > tmp_b->content_size && count_ops(tmp_b->content_size, lst_a) >= 0) ||
				(*res < tmp_b->content_size && count_ops(tmp_b->content_size, lst_a) <= 0))
			{
				*res = tmp_b->content_size;
				min = minin(opti(i, lst_b), count_ops(tmp_b->content_size, lst_a), lst_a, lst_b);
				mini = i;
			}
		}
		tmp_b = tmp_b->next;
		i++;
	}

	if(mini < j - mini)
		return (mini);
	else
		return (-1 * (j - mini));
}

void doo4(t_list **lst_a, t_list **lst_b, int j)
{
    int i;
    int c;
    int g;
    int d;
    d = 0;
    while(*lst_b)
    {
		i = find(*lst_a, *lst_b, &g);
		c = count_ops(g, *lst_a);
        if (i * c < 0)
		{
			if(i < 0)
			{
				if(i + c > max(ft_lstlen(*lst_b) + i, c))
					i = ft_lstlen(*lst_b) + i;
			}
			else
			{
				if(i + c > max(ft_lstlen(*lst_a) + c, i))
					c = ft_lstlen(*lst_a) + c;
			}
    	}
        if(i * c <= 0)
		{
        	if(i >= 0)
        	{
        	    while(i--)
        	        rb(lst_b, 1);
        	}
        	else
        	{
        	    while (i++)
        	        rrb(lst_b, 1);
        	}
        	if(c >= 0)
        	{
        	    while(c--)
        	        ra(lst_a, 1);
        	}
        	else
        	{
        	    while (c++)
        	        rra(lst_a, 1);
        	}
        }
        else
        {
        	if(i >= 0 && c >= 0)
			{
			    while(i && c)
			    {
			        rr(lst_a, lst_b, 1);
			        i--;
			        c--;
			    }
			    while(i-- > 0)
			        rb(lst_b, 1);
			    while(c-- > 0)
			        ra(lst_a, 1);
			}
			else
			{
			    while (i && c)
			    {
			        rrr(lst_a, lst_b, 1);
			    	i++;
			        c++;
			    }
			    while(i++ < 0)
			        rrb(lst_b, 1);
			    while(c++ < 0)
			        rra(lst_a, 1);
			}
        }
        pa(lst_a, lst_b, 1);
        //print_list(*lst_a, *lst_b, j);
    }
}

void roll(t_list **lst)
{
    t_list *tmp = *lst;
    int i = 0;
    while(tmp && tmp->next && tmp->content_size < tmp->next->content_size)
    {
        tmp = tmp->next;
        i++;
    }
    if(i < ft_lstlen(*lst) - i)
    {
        while((*lst)->content_size > ft_lstlast(*lst))
            ra(lst, 1);
    }
    else
    {
        while((*lst)->content_size > ft_lstlast(*lst))
            rra(lst, 1);
    }
}

int		main(int argc, char **argv)
{
	t_list	*lst_a = NULL;
	t_list	*lst_b = NULL;
	int c;

	lst_a = set_list(argc, argv);
	c = get_max_len(lst_a);

	start(&lst_a, &lst_b, c);
	//print_list(lst_a, lst_b, c);
	doo4(&lst_a, &lst_b, c);
	//print_list(lst_a, lst_b, c);
	roll(&lst_a);
    //print_list(lst_a, lst_b, c);
}

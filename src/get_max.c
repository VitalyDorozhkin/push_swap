#include <push_swap.h>

int get_max(t_list *lst_b)
{
    int		max;
    t_list	*tmp;

    max = -2147483647;
    tmp = lst_b;
    while(tmp)
    {
        if((int)tmp->content_size > max)
            max = tmp->content_size;
        tmp = tmp->next;
    }
    return (max);
}

int get_premax(t_list *lst_b)
{
    int		premax;
    int		max;
    t_list	*tmp;

    max = -2147483647;
    premax = -2147483648;
    tmp = lst_b;
    while(tmp)
    {
        if((int)tmp->content_size > max)
        {
            premax = max;
            max = (int)tmp->content_size;
        }
        else if((int)tmp->content_size > premax)
            premax = (int)tmp->content_size;
        tmp = tmp->next;
    }
    return (premax);
}

int get_prepremax(t_list *lst_b)
{
    int		prepremax;
    int		premax;
    int		max;
    t_list	*tmp;

    max = -2147483646;
    premax = -2147483647;
    prepremax = -2147483648;
    tmp = lst_b;
    while(tmp)
    {
        if((int)tmp->content_size > max)
        {
            prepremax = premax;
            premax = max;
            max = (int)tmp->content_size;
        }
        else if((int)tmp->content_size > premax)
        {
            prepremax = premax;
            premax = (int)tmp->content_size;
        }
        else if ((int)tmp->content_size > prepremax)
            prepremax = (int)tmp->content_size;
        tmp = tmp->next;
    }
    return (prepremax);
}

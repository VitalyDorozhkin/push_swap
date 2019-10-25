#include <push_swap.h>


int		main(int argc, char **argv)
{
	t_list	*lst_a = NULL;
	t_list	*lst_b = NULL;
	int c;
    char *comand;
	lst_a = set_list(argc, argv);
	c = get_max_len(lst_a);

    while (get_next_line(0, &comand))
    {
        (ft_strcmp(comand, "sa")) ? (void)0 : sa(lst_a, 0);
        (ft_strcmp(comand, "sb")) ? (void)0 : sb(lst_b, 0);
        (ft_strcmp(comand, "ss")) ? (void)0 : ss(lst_a, lst_b, 0);
        (ft_strcmp(comand, "pa")) ? (void)0 : pa(&lst_a, &lst_b, 0);
        (ft_strcmp(comand, "pb")) ? (void)0 : pb(&lst_a, &lst_b, 0);
        (ft_strcmp(comand, "ra")) ? (void)0 : ra(&lst_a, 0);
        (ft_strcmp(comand, "rb")) ? (void)0 : rb(&lst_b, 0);
        (ft_strcmp(comand, "rr")) ? (void)0 : rr(&lst_a, &lst_b, 0);
        (ft_strcmp(comand, "rra")) ? (void)0 : rra(&lst_a, 0);
        (ft_strcmp(comand, "rrb")) ? (void)0 : rrb(&lst_b, 0);
        (ft_strcmp(comand, "rrr")) ? (void)0 : rrr(&lst_a, &lst_b, 0);
    }

    print_list(lst_a, lst_b, c);
    if(lst_b || !lst_a)
    {
        ft_printf("KO");
        return (0);
    }
    while (lst_a->next)
    {
        if (lst_a->content_size >= lst_a->next->content_size)
        {
            ft_printf("KO");
            return 0;
        }
        lst_a = lst_a->next;
    }
    ft_printf("OK");
}

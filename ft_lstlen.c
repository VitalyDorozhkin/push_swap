int ft_lstlen(t_list *lst)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = lst;
	while(lst)
	{
		lst = lst->next;
		i++;
	}	
	return (i);
}
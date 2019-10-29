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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quick_sort(t_list **lst_a, t_list **lst_b)
{
	int midi;
	int lena;
	int i;

	while ((lena = ft_lstlen(*lst_a)) > 3)
	{
		midi = mid(*lst_a);
		i = 0;
		while (i < lena / 2 && lena - i > 3)
			if ((*lst_a)->content_size < midi && ++i)
			{
				pb(lst_a, lst_b, 1);
				if ((*lst_b)->content_size > mid(*lst_b))
				{
					if (i < lena / 2 && lena - i > 3 &&
						(*lst_a)->content_size >= midi)
						rr(lst_a, lst_b, 1);
					else
						rb(lst_b, 1);
				}
			}
			else
				ra(lst_a, 1);
	}
}

void	ft_lstfree(t_list **alst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	while (tmp && alst)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}

void	read_flags_a(int *argc, char ***argv)
{
	int		fd;
	char	*line;

	if ((*argv)[1][0] == '-' && (*argv)[1][1] == 'f')
	{
		fd = open((*argv)[2], O_RDONLY);
		get_next_line(fd, &line);
		(*argv)[2] = line;
		(*argv)++;
		(*argc)--;
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	if (argc == 1)
		exit(0);
	read_flags_a(&argc, &argv);
	lst_a = set_list(argc, argv);
	is_dub(lst_a);
	is_sort(lst_a);
	is_small(&lst_a);
	quick_sort(&lst_a, &lst_b);
	sort_three(&lst_a);
	push_back(&lst_a, &lst_b);
	roll(&lst_a);
	ft_lstfree(&lst_a);
	ft_lstfree(&lst_b);
	free(lst_a);
	free(lst_b);
}

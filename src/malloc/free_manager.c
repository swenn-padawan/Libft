/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:01:33 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/26 22:36:31 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	**alloc_collector(void)
{
	static t_list	*lst;

	if (!lst)
		lst = ft_lstnew(NULL);
	return (&lst);
}

__attribute__((destructor))
static void	free_alloc_collector(void)
{
	t_list	**lst;
	t_list	*tmp;

	lst = alloc_collector();
	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	free(tmp->content);
	free(tmp);
}

void	push(void *malloc_address)
{
	t_list	**lst;

	lst = alloc_collector();
	ft_lstadd_front(lst, ft_lstnew(malloc_address));
}

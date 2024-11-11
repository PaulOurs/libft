/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:02 by paubello          #+#    #+#             */
/*   Updated: 2024/11/11 14:05:40 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (ft_lstclear(&new_lst, del), NULL);
		tmp->content = f(lst->content);
		tmp->next = NULL;
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

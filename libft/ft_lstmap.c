/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:50:01 by dnguyen           #+#    #+#             */
/*   Updated: 2022/10/15 10:44:57 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
Creates a new list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	head = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist -> next = ft_lstnew(f(lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		newlist = newlist -> next;
		lst = lst->next;
	}
	newlist -> next = NULL;
	return (head);
}

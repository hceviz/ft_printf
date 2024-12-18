/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:49:07 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:24:45 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*I just checked !lst || !f cuz we use del in certain condition so 
 it can be null at the beginning. During the iteration of lst in 
 every iteration i checked the lst->content 
if it is null or not null by trying to create new node with lstnew 
and lst->content is null, the need to use del function appears.
if it is not null we add the lst to end of res as mentioned in pdf.
lastly i update head address*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (res);
}

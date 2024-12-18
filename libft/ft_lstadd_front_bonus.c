/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:34:46 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 13:05:06 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//new is the node to be added
//firstly i checked the whole linked list is null or not
//after than i checked the first node is null or not
//if both are okay i set the current head address (*lst) to new->next
//if just first if ok i updated head address with new's address
//because new is new :)
//*lst is true means there are at least one more space for new nodes
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
	else
		return ;
}

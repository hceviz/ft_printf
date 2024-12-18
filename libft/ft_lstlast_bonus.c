/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:06 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/09 18:19:51 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*checkpoint;

	if (lst)
		checkpoint = lst->next;
	while (lst)
	{
		if (!checkpoint)
			return (lst);
		lst = lst->next;
		checkpoint = checkpoint->next;
	}
	return (NULL);
}

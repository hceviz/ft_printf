/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:05:51 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:30:16 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if you set little or big as NULL it gives segmentation fault like original one
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	x = 0;
	y = 0;
	while (big[x] != '\0' && x < len)
	{
		if (big[x] == little[y])
		{
			while (big[x + y] == little[y] && x + y < len)
			{
				if (little[y + 1] == '\0')
					return ((char *)big + x);
				y++;
			}
			y = 0;
		}
		x++;
	}
	return (NULL);
}

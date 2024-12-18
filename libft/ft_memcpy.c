/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:26:11 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:28:04 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//we are working in address level
//that is why using unsigned char is a good practice
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*source;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:45 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:27:34 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;

	chr = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == chr)
			return ((char *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

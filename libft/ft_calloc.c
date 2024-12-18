/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:41:40 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:26:36 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// we should return void array
//because we are allocating memory for an array
//because of calloc behavior
//we need to fill the array with zeros if the allocation is succesful
//we check overflow with nmemb != (total / size), because when we
//initialise total, if there is overflow, the value will be max
//value of size_t but the real value will be more than max size_t
//if there is overflow, after initialisation of total, the value of nmemb
//will not be same when we compare with total/size
//i just checked in one if statement cuz if one of them is exceed other's
// result will not be correct or vice versa
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	max;

	max = 4294967295;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size && (nmemb > (max / size)))
		return (NULL);
	arr = (void *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:22:46 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/10 16:27:03 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_dgt(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long		num;
	size_t		count;
	char		*res;

	num = n;
	count = count_dgt(num);
	res = (char *)ft_calloc(count_dgt(n) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	count--;
	while (count > 0)
	{
		res[count] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	if (res[0] != '-')
		res[0] = (num % 10) + '0';
	return (res);
}

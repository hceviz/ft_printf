/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:49:27 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/09 12:52:38 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		putnbr(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (fd < 0)
		return ;
	putnbr(num, fd);
}

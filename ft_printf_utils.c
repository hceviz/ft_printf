/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:18 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/18 15:16:52 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

void	print_ptr(void *ptr)
{
	char		*hex;
	uintptr_t	num;

	num = (uintptr_t)ptr;
	if (num == 0)
	{
		write(1, '0', 1);
		return ;
	}
	write(1, '0', 1);
	write(1, 'x', 1);
	while (num > 0)
	{
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
		num /= 16;
	}
}




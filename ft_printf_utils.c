/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:18 by hceviz            #+#    #+#             */
/*   Updated: 2025/01/05 13:40:04 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print_both_x has an int flag
//which specify is it upper or lower case
//it allows us to handle both case in one func
// case_flag == 1 means that it is lower 0 means upper

//check print_both_x when to return -1
int	print_ptr(void *ptr)
{
	uintptr_t	num;
	int			count;

	if (!ptr)
		return (-1);
	num = (uintptr_t)ptr;
	if (num == 0)
		return (print_c('0'));
	print_c('0');
	print_c('x');
	count = 2;
	while (num > 0)
	{
		count += print_c("0123456789abcdef"[num % 16]);
		num /= 16;
	}
	return (count);
}

int	print_c(int c)
{
	char	x;

	x = (char)c;
	write(1, &x, 1);
	return (1);
}

int	print_d_i(int num)
{
// control with max min int
	char	*number;
	int		count;

	count = 0;
	number = ft_itoa(num);
	count = print_s(number);
	free(number);
	return (count);
}

int	print_u(unsigned int num)
{
	int	written;

	written = 0;
	if (num >= 10)
		written += print_u(num / 10);
	written += print_c((num % 10) + '0');
	return (written);
}


int	print_both_x(unsigned int num, unsigned int case_flag)
{
	char	*base;
	int		written;

	written = 0;
	if (case_flag == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		written = print_both_x(num / 16, case_flag);
	print_c(base[num % 16]);
	return (written + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:18 by hceviz            #+#    #+#             */
/*   Updated: 2025/01/13 16:21:02 by hceviz           ###   ########.fr       */
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
	unsigned long	num;
	int				count;

	num = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	print_c('0');
	print_c('x');
	count = 2;
	count += print_hex(num, 1);
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


int	print_hex(unsigned long num, unsigned int case_flag)
{
	char			*base;
	long			written;
	unsigned long	number;
	
	written = 0;
	number = (unsigned long)num;
	if (case_flag == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		written = print_hex(number / 16, case_flag);
	print_c(base[number % 16]);
	return (written + 1);
}


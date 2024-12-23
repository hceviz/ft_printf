/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:18 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/23 16:34:40 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

//print_both_x has an int flag
//which specify is it upper or lower case
//it allows us to handle both case in one func
// case_flag == 1 means that it is lower 0 means upper

//check print_ptr is case sensitive
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
	return (print_d_i(num));
}

int	print_both_x(unsigned int num, unsigned int case_flag)
{
	int		count;
	char	arr[50];
	int		i;

	if (num == 0)
		return (print_c('0'));
	count = 0;
	while (num > 0 && case_flag == 1)
	{
		arr[count] = "0123456789abcdef"[num % 16];
		num /= 16;
		count++;
	}
	while (num > 0 && case_flag == 0)
	{
		arr[count] = "0123456789ABCDEF"[num % 16];
		num /= 16;
		count++;
	}
	if (count == 0)
		return (-1);
	i = count;
	while (i >= 0)
		print_c(arr[i--]);
	return (count);
}

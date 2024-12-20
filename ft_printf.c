/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:38:25 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/20 20:36:00 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>
//be careful with argument promotion
//promotion char to int
// pointers cant be promoted

/* print_c(*(s++)) is same with
vvvvvvvvvvvvvv
 print_c(*s)
 s++;
 */

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

//-----------------------------
int	print_s(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += print_c(*(s++));
	return (count);
}

int	process_specifier(char flag, va_list ap)
{
	if (flag == 'd' || flag == 'i')
		return (print_d_i(va_arg(ap, int)));
	else if (flag == 'c')
		return (print_c(va_arg(ap, int)));
	else if (flag == 's')
		return (print_s(va_arg(ap, char *)));
	else if (flag == 'p')
		return (print_ptr(va_arg(ap, void *)));
	else if (flag == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else if (flag == 'x')
		return (print_both_x(va_arg(ap, int), 1));
	else if (flag == 'X')
		return (print_both_x(va_arg(ap, int), 0));
	else if (flag == '%')
		return (print_c((int)flag));
	else
		return (-1);
}

int	ft_printf(const char *flag, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	va_start(ap, flag);
	count = 0;
	temp = 0;
	while (*flag)
	{
		temp = 0;
		if (*flag == '%')
		{
			temp = process_specifier(*(++flag), ap);
			if (temp == -1)
				return (-1);
			count += temp;
			flag++;
		}
		else
		{
			count += print_c((*flag));
			flag++;
		}
	}
	return (1);
}

int main()
{
	ft_printf("%x", 2042);
	printf("\n%x", 2042);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:50 by hceviz            #+#    #+#             */
/*   Updated: 2025/01/13 16:13:00 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *flag, ...);
int	print_ptr(void *ptr);
int	print_d_i(int num);
int	print_u(unsigned int num);
int	print_hex(unsigned long num, unsigned int case_flag);
int	print_c(int c);
int	print_s(char *s);

#endif

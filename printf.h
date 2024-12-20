/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:50 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/20 20:35:57 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

int	print_ptr(void *ptr);
int	print_d_i(int num);
int	print_u(unsigned int num);
int	print_both_x(unsigned int num, unsigned int case_flag);
int	print_c(int c);
int	print_s(char *s);

#endif
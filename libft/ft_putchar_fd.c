/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:10:10 by hceviz            #+#    #+#             */
/*   Updated: 2024/12/19 18:08:21 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*File descriptors are not till 2. They are standart ones
When a program opens a new resource (file, socket, pipe),
the operating system assigns the LOWEST AVAILABLE FILE 
DESCRIPTOR starting from 3*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

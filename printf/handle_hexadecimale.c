/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:33:26 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:33:28 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hexa(va_list args, t_flags found)
{
	int				j;
	unsigned int	i;

	j = 0;
	i = va_arg(args, unsigned int);
	if (found.hashtage)
	{
		if (i != 0)
			j = write(1, "0x", 2);
	}
	return (ft_putnbr_base(i, "0123456789abcdef") + j);
}

int	handle_hexa2(va_list args, t_flags found)
{
	int				j;
	unsigned int	i;

	j = 0;
	i = va_arg(args, unsigned int);
	if (found.hashtage)
	{
		if (i != 0)
			j = write(1, "0X", 2);
	}
	return (ft_putnbr_base(i, "0123456789ABCDEF") + j);
}

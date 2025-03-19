/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:33:01 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:33:03 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_num(va_list args, t_flags found)
{
	int	i;
	int	j;

	j = 0;
	i = va_arg(args, int);
	if (found.plus)
	{
		if (i >= 0)
			j = write(1, "+", 1);
	}
	else if (found.space)
	{
		if (i >= 0)
			j = write(1, " ", 1);
	}
	return (ft_putnbr(i, "0123456789") + j);
}

int	handle_unnum(va_list args, t_flags found)
{
	unsigned int	i;

	(void)found;
	i = va_arg(args, unsigned int);
	return (ft_putnbr_base(i, "0123456789"));
}

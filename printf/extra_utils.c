/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:29:42 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:29:46 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flags *yes)
{
	(*yes).hashtage = 0;
	(*yes).plus = 0;
	(*yes).space = 0;
}

int	print(char *v, int i)
{
	int	j;

	j = 0;
	while (i >= 0)
	{
		j += write(1, &v[i], 1);
		i--;
	}
	return (j);
}

int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int		i;
	char	v[17];
	int		count;

	count = 0;
	if (nbr == 0)
	{
		count += write(1, base, 1);
		return (count);
	}
	i = 0;
	while (nbr > 0)
	{
		v[i++] = base[nbr % len(base)];
		nbr /= len(base);
	}
	count += print(v, i - 1);
	return (count);
}

int	ft_putnbr(int nb, char base[10])
{
	int		count;
	int		i;
	char	v[12];

	i = 0;
	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb == 0)
		count = write(1, "0", 1);
	if (nb < 0)
	{
		count = write(1, "-", 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		v[i++] = base[nb % 10];
		nb /= 10;
	}
	count += print(v, i - 1);
	return (count);
}

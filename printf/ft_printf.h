/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:05 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:31:08 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct wich_flags
{
	int		plus;
	int		hashtage;
	int		space;
}			t_flags;

typedef struct formats
{
	char	type;
	int		(*handle)(va_list args, t_flags found);
}			t_frmt;

int			work(const char *format, t_frmt list_of_formats[10], va_list args);
int			write_format(const char *str, va_list args,
				t_frmt list_of_formats[10], int *flag);
int			ft_printf(const char *format, ...);
void		init_flag(t_flags *yes);
t_flags		check_flags(const char *str, int *i, int *flag);
void		initial_list(t_frmt (*list)[10]);
int			handle_char(va_list args, t_flags found);
int			handle_string(va_list args, t_flags found);
int			handle_num(va_list args, t_flags found);
int			handle_pointer(va_list args, t_flags found);
int			handle_unnum(va_list args, t_flags found);
int			handle_hexa(va_list args, t_flags found);
int			handle_hexa2(va_list args, t_flags found);
int			ft_putnbr_base(unsigned long nbr, char *base);
int			ft_putnbr(int nb, char base[10]);
int			len(char *base);
int			print(char *v, int i);

#endif

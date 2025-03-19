/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:30:50 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:30:55 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initial_list(t_frmt (*list)[10])
{
	(*list)[0].type = 'c';
	(*list)[0].handle = handle_char;
	(*list)[1].type = 's';
	(*list)[1].handle = handle_string;
	(*list)[2].type = 'p';
	(*list)[2].handle = handle_pointer;
	(*list)[3].type = 'd';
	(*list)[3].handle = handle_num;
	(*list)[4].type = 'i';
	(*list)[4].handle = handle_num;
	(*list)[5].type = 'u';
	(*list)[5].handle = handle_unnum;
	(*list)[6].type = 'x';
	(*list)[6].handle = handle_hexa;
	(*list)[7].type = 'X';
	(*list)[7].handle = handle_hexa2;
	(*list)[9].type = 0;
	(*list)[9].handle = NULL;
}

t_flags	check_flags(const char *str, int *i, int *flag)
{
	t_flags	there_is;

	init_flag(&there_is);
	*flag = 0;
	while (str[*i] == ' ' || str[*i] == '#' || str[*i] == '+')
	{
		if (str[*i] == ' ')
		{
			there_is.space = 1;
			(*flag)++;
		}
		else if (str[*i] == '#')
		{
			there_is.hashtage = 1;
			(*flag)++;
		}
		else
		{
			there_is.plus = 1;
			(*flag)++;
		}
		*i = *i + 1;
	}
	return (there_is);
}

int	write_format(const char *str, va_list args, t_frmt list_of_formats[10],
		int *flag)
{
	int		j;
	char	specifier;
	t_flags	found;

	j = 0;
	found = check_flags(str, &j, flag);
	specifier = str[j];
	while (list_of_formats[j].handle)
	{
		if (list_of_formats[j].type == specifier)
			return (list_of_formats[j].handle(args, found));
		j++;
	}
	return (0);
}

int	work(const char *format, t_frmt list_of_formats[10], va_list args)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				count += write(1, "%", 1);
			else
				count += write_format(&format[i + 1], args, list_of_formats,
						&flag);
			i = i + 2 + flag;
		}
		else
			count += write(1, &format[i++], 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_frmt	list_of_formats[10];

	if (!format)
		return (-1);
	initial_list(&list_of_formats);
	va_start(args, format);
	return (work(format, list_of_formats, args));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:20:49 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/20 14:17:30 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	output(char c, va_list arglist);

int	ft_printf(char *format, ...)
{
	va_list	arglist;
	size_t	count;

	va_start(arglist, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += output(*(format + 1), arglist);
			format++;
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arglist);
	return (count);
}

static int	output(char c, va_list arglist)
{
	int		d;
	char	*s;
	char	ch;
	size_t	count;

	count = 0;
	d = 0;
	if (c == 'd')
	{
		d = va_arg(arglist, int);
		ft_putstr(ft_itoa(d));
		count += ft_strlen(ft_itoa(d));
	}
	else if (c == 's')
	{
		s = va_arg(arglist, char *);
		ft_putstr(s);
		count += ft_strlen(s);
	}
	else if (c == 'c')
	{
		ch = va_arg(arglist, int);
		ft_putchar(ch);
		count++;
	}
	else if (c == '%') 
	{
		ft_putchar('%');
		count++;
	}
	printf("output count: %s\n", count);
	return (count);
}

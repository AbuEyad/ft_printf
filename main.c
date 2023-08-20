/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:54 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/20 15:33:03 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int				ft_printf(char *format, ...);
static size_t	output(char c, va_list arglist);

int	main(void)
{
	int	count;

	count = 0;
	count = ft_printf("this %s %d", "hisham", 10);
	printf("\ncount is: %d\n", count);
	return (0);
}

int	ft_printf(char *format, ...)
{
	va_list	arglist;
	size_t	count;

	count = 0;
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

static size_t	output(char c, va_list arglist)
{
	int		d;
	char	*s;
	char	ch;
	size_t	count;

	count = 0;
	d = 0;
	if (c == 'd')
		count += put_d(arglist);
	else if (c == 's')
		count += put_s(arglist);
	else if (c == 'c')
	{
		ft_putchar(va_arg(arglist, int));
		count++;
	}
	else if (c == '%') 
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

static size_t	put_d(va_list arg)
{
	int	d;

	d = 0;
	d = va_arg(arg, int);
	ft_putstr(ft_itoa(d));
	return (ft_strlen(ft_itoa(d)));
}

static size_t	put_s(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	ft_putstr(s);
	return (ft_strlen(s));
}

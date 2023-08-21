/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:54 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 11:14:52 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(char *format, ...);
static int	output(char c, va_list arglist);

int	main(void)
{
	int	count;

	count = 0;
	count = ft_printf("this %s%d%c%d%d%s   ", "hisham", 10, 'H', -5, 5, "Eyad");
	ft_printf("%d\n", count);
	return (0);
}

int	ft_printf(char *format, ...)
{
	int	count;
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
			ft_putchar_plus(*format);
			count++;
		}
		format++;
	}
	va_end(arglist);
	return (count);
}

static int	output(char c, va_list arglist)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_plus(va_arg(arglist, int));
	else if (c == 's')
		count += ft_putstr_plus(va_arg(arglist, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_plus((long)va_arg(arglist, int));
	else if (c == 'u')
		count += ft_put_u_int(va_arg(arglist, unsigned int));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(arglist, uintptr_t));
	else if (c == 'x' || c == 'X')
		count += put_hex(va_arg(arglist, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_plus('%');
	return (count);
}

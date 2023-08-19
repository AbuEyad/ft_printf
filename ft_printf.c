/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:20:49 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/19 17:54:37 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "./libft/libft.h"

static void	output(char c, va_list arglist);

int	ft_printf(char *format, ...)
{
	va_list	arglist;

	va_start(arglist, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			output(*(format + 1), arglist);
			format++;
		}
		else
			printf("%c", *format);
		format++;
	}
	va_end(arglist);
	printf("\n");
	return (0);
}

static void	output(char c, va_list arglist )
{
	int		d;
	char	*s;
	char	ch;

	d = 0;
	if (c == 'd' || c == 's' || c == 'c')
	{
		if (c == 'd')
		{
			d = va_arg(arglist, int);
			ft_putnbr_fd(d, 1);
			ft_putchar_fd(' ', 1);
		}
		else if (c == 's')
		{
			s = va_arg(arglist, char *);
			printf("%s ", s);
		}
		else if (c == 'c')
		{
			ch = va_arg(arglist, int);
			printf("%c ", c);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:43:17 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/20 22:05:14 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_print_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_plus((num + '0'));
		else
			ft_putchar_plus((num - 10 + 'a'));
	}
}

int	ft_put_ptr(uintptr_t ptr)
{
	int	length;

	length = 0;
	length += ft_putstr_plus("0x");
	if (ptr == 0)
		length += ft_putchar_plus('0');
	else
	{
		ft_print_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:54 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/21 15:20:32 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

static int	output(char c, va_list arglist);

int	main(void)
{
	unsigned int	count;

	count = -1;
	printf("printf    %X", count);
	return (0);
}

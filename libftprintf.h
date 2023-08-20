/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:18:16 by habu-zua          #+#    #+#             */
/*   Updated: 2023/08/20 14:06:48 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

// int	ft_printf(char *format, ...);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);


#endif
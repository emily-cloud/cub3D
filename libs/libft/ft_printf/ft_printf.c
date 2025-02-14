/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:42:09 by hai               #+#    #+#             */
/*   Updated: 2024/05/18 11:31:59 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(ap, long long unsigned int));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_print_digit((long unsigned int)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_printx((long unsigned int)va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count += ft_printupx((long unsigned int)va_arg(ap, unsigned int));
	else if (specifier == '%')
		count += ft_print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format((*++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

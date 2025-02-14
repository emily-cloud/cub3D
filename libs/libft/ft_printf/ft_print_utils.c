/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:09:38 by hai               #+#    #+#             */
/*   Updated: 2024/05/18 11:31:55 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (*str)
	{
		ft_print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	ft_print_ptr(long long unsigned int n)
{
	int	count;

	count = 0;
	if (!n)
	{
		count = ft_print_str("(nil)");
		return (count);
	}
	else
	{
		count = ft_print_str("0x") + ft_printx(n);
		return (count);
	}
}

int	ft_print_digit(long n)
{
	int			count;
	char		*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n) + 1);
	}
	else if (n < 10)
	{
		count = ft_print_char(symbols[n]);
		return (count);
	}
	else
	{
		count += ft_print_digit(n / 10);
		count += ft_print_digit(n % 10);
		return (count);
	}
}

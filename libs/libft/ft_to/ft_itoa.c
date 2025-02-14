/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:38:18 by hai               #+#    #+#             */
/*   Updated: 2023/12/01 12:19:00 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static long	number_set(long int n)
{
	long int	num;

	num = 1;
	if (n < 0)
		num *= -n;
	else
		num *= n;
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	int				len;
	int				sign;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = get_size(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	number = number_set(n);
	while (len--)
	{
		str[len] = number % 10 + 48;
		number = number / 10;
	}
	if (sign)
		*str = 45;
	return (str);
}

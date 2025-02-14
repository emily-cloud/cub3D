/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:23:48 by hai               #+#    #+#             */
/*   Updated: 2023/11/23 09:30:50 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	number;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
		break ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
/*
int	main(void)
{
	char	str[] = " -1234ab567";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:09:52 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/28 13:14:42 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	handlermax(char *str, int i, int sign, long res)
{
	int	j;

	j = 0;
	while (*(str + i) == 48)
		i++;
	while ((*(str + i) >= '0' && *(str + i) <= '9')
		&& (*(str + i) != '\0' && *(str + i) != 32 && *(str + i) != '	'))
	{
		res *= 10;
		res += *(str + i) - '0';
		i++;
	}
	res = res * sign;
	return (res);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;
	char	*ptr;

	i = 0;
	sign = 1;
	res = 0;
	ptr = (char *)nptr;
	while (*(ptr + i) == 32 || (*(ptr + i) >= 9 && *(ptr + i) <= 16))
		i++;
	if (*(ptr + i) == '-')
	{
		sign = -1;
		i++;
	}
	else if (*(ptr + i) == '+')
		i++;
	return (handlermax(ptr, i, sign, res));
}

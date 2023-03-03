/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:02:09 by ichouare          #+#    #+#             */
/*   Updated: 2023/03/01 12:06:48 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_pop(char **str, int **stack_a, int *top, int i)
{
	int	j;

	j = 0;
	*top = -1;
	while (i >= 0)
	{
		*top = *top + 1;
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (1);
		(*stack_a)[*top] = ft_atoi(str[i]);
		i--;
	}
	return (0);
}

void	ft_free(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}

void	ft_error(char *str, int length)
{
	if (str == NULL)
		exit (0);
	write (1, str, length + 1);
	exit (0);
}

void	is_sorted(int *stack_a, int top)
{
	int	i;
	int	j;

	i = top;
	j = top;
	while (i > 0)
	{
		if (stack_a[j] < stack_a[j - 1])
			j--;
		i--;
	}
	if (j == 0)
		exit (0);
}

int	check_sort(int *stack_a, int top)
{
	int	i;
	int	res;

	i = top;
	res = 0;
	while (i > 0)
	{
		if (stack_a[i] > stack_a[i - 1])
		{
			res = 1;
			break ;
		}
		else
			res = 0;
		i--;
	}
	if (res == 1)
		write(1, "KO\n", 4);
	else
		write(1, "OK\n", 4);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:02:09 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 17:37:39 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_pop(char **str, int **stack_a, int *top, int i)
{
	int	j;

	j = 0;
	while (i >= 0)
	{
		*top = *top + 1;
		(*stack_a)[*top] = ft_atoi(str[i]);
		i--;
	}
}

void	ft_free(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}

void	ft_error(char *str, int length)
{
	write (1, str, length);
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

	i = top;
	while (i > 0)
	{
		if (stack_a[i] > stack_a[i - 1])
			return (1);
		i--;
	}
	return (0);
}

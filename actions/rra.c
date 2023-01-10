/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:55:56 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:39:31 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(int *a, int top)
{
	int	i;
	int	j;
	int	tmp;
	int	*tab;

	if (top <= 0)
		return (0);
	i = top;
	j = 0;
	tab = (int *) malloc(top * sizeof(int) + 1);
	while (i > 0)
		tab[j++] = a[i--];
	tmp = a[i];
	i = 0;
	while (i < top)
	{
		a[i++] = tab[j - 1];
		j--;
	}
	a[i] = tmp;
	write (1, "rra\n", 4);
	free (tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:06:42 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:41:53 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rrb(int *b, int top)
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
		tab[j++] = b[i--];
	tmp = b[i];
	i = 0;
	while (i < top)
	{
		b[i++] = tab[j - 1];
		j--;
	}
	b[i] = tmp;
	write (1, "rrb\n", 4);
	free (tab);
	return (0);
}

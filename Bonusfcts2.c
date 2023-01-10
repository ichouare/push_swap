/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bonusfcts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:19 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:17:26 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ra(int *a, int topa)
{
	int	tmp;

	if (topa <= 0)
		return (0);
	tmp = 0;
	tmp = a[topa];
	while (topa > 0)
	{
		a[topa] = a[topa - 1];
		topa--;
	}
	a[0] = tmp;
	return (0);
}

int	rb(int *b, int topb)
{
	int	i;
	int	tmp;

	if (topb <= 0)
		return (0);
	i = topb;
	tmp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = tmp;
	return (0);
}

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
	free (tab);
	return (0);
}

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
	free (tab);
	return (0);
}

int	rrr(int *a, int topa, int *b, int topb)
{
	rra(a, topa);
	rrb(b, topb);
	return (0);
}

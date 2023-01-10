/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:14:39 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 15:31:25 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(int *a, int *b, int *topa, int *topb)
{
	if (*topb == -1)
		return (0);
	*topa = *topa + 1;
	a[*topa] = b[*topb];
	*topb = *topb - 1;
	write (1, "pa\n", 3);
	return (0);
}

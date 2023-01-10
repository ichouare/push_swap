/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:46:29 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 16:31:35 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pb(int *a, int *b, int *topa, int *topb)
{
	if (*topa == -1)
		return (0);
	*topb = *topb + 1;
	b[*topb] = a[*topa];
	*topa = *topa - 1;
	write (1, "pb\n", 3);
	return (0);
}

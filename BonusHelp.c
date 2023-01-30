/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BonusHelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:32:54 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/28 13:10:57 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_arrb(t_Bonus *tvars)
{
	int	i;
	int	j;

	i = tvars->top;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tvars->a[i] == tvars->a[j])
			{
				ft_free(tvars->a, tvars->b);
				ft_error("Error\n", 6);
			}
			j--;
		}
		i--;
	}
	return (1);
}

void	check_enter(char *str2)
{
	if (ft_strcmp(str2, "ra", 2) != 0 && ft_strcmp(str2, "pa", 2) != 0
		&& ft_strcmp(str2, "pb", 2) != 0 && ft_strcmp(str2, "rb", 2) != 0
		&& ft_strcmp(str2, "rb", 2) != 0 && ft_strcmp(str2, "rra", 3) != 0
		&& ft_strcmp(str2, "rrb", 3) != 0 && ft_strcmp(str2, "rrr", 3) != 0
		&& ft_strcmp(str2, "sb", 2) != 0 && ft_strcmp(str2, "ss", 2) != 0
		&& ft_strcmp(str2, "sa", 2) != 0)
	{
		write(1, "Error", 6);
		exit(1);
	}
}

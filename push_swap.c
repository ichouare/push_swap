/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:26 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/11 17:29:39 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(char **str, int *i)
{
	int	j;

	while (str[*i])
	{
		if (ft_strlen(str[*i]) == 1)
		{
			if (str[*i][0] < '0' || str[*i][0] > '9' )
				ft_error("some arguments aren't integers\n", 41);
		}
		else
		{
			if (str[*i][0] != '-' && str[*i][0] != '+'
				&& (str[*i][0] < 48 || str[*i][0] > 57))
				ft_error("some arguments aren't integers\n", 41);
			j = 1;
			while (str[*i][j])
			{
				if (str[*i][j] < '0' || str[*i][j] > '9')
					ft_error("some arguments aren't integers\n", 41);
				j++;
			}
		}
		*i = *i + 1;
	}
}

void	ft_sort(t_list *tvars)
{
	if (tvars->top == 2)
		sort_small_stack(tvars->a, tvars->top);
	else if (tvars->top == 4)
		sort_medium_stack(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	else
		sort_large_stack(tvars);
}

int	main(int argc, char **agrv)
{
	char	**str;
	int		i;
	int		j;
	t_list	tvars;

	tvars.top = -1;
	tvars.topb = -1;
	i = 0;
	str = check_parms(argc, agrv);
	check_stack(str, &i);
	tvars.a = (int *)malloc(i * sizeof(int));
	tvars.b = (int *)malloc(i * sizeof(int));
	i--;
	ft_pop(str, &tvars.a, &tvars.top, i);
	is_sorted(tvars.a, tvars.top);
	check_arr(&tvars);
	ft_sort(&tvars);
	return (0);
}

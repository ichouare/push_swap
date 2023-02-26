/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:26 by ichouare          #+#    #+#             */
/*   Updated: 2023/02/24 18:00:33 by ichouare         ###   ########.fr       */
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
				ft_error("some arguments aren't integers\n", 31);
		}
		else
		{
			if (str[*i][0] != '-' && str[*i][0] != '+'
				&& (str[*i][0] < 48 || str[*i][0] > 57))
				ft_error("some arguments aren't integers\n", 31);
			j = 1;
			while (str[*i][j])
			{
				if (str[*i][j] < '0' || str[*i][j] > '9')
					ft_error("some arguments aren't integers\n", 31);
				j++;
			}
		}
		*i = *i + 1;
	}
}

void	ft_sort(t_list *tvars)
{
	tvars->topb = -1;
	if (tvars->top == 1)
	{
		sa(tvars->a, tvars->top);
		free(tvars->a);
		free(tvars->b);
		exit (0);
	}
	if (tvars->top == 2)
		sort_small_stack(tvars->a, tvars->top);
	else if (tvars->top == 4 || tvars->top == 3)
		sort_medium_stack(tvars->a, tvars->b, &tvars->top, &tvars->topb);
	else
		sort_large_stack(tvars);
}

int	main(int argc, char **agrv)
{
	int		i;
	t_list	tvars;

	i = 0;
	tvars.str = check_parms(argc, agrv);
	check_stack(tvars.str, &i);
	tvars.a = (int *)malloc(i * sizeof(int));
	tvars.b = (int *)malloc(i * sizeof(int));
	if (tvars.a == NULL || tvars.b == NULL)
		return (0);
	i--;
	if (ft_pop(tvars.str, &tvars.a, &tvars.top, i) == 1)
	{
		ft_free(tvars.a, tvars.b);
		ft_error("arguments are bigger than integer/duplicates\n", 45);
	}
	free_str(&tvars);
	free(tvars.str);
	is_sorted(tvars.a, tvars.top);
	check_arr(&tvars);
	ft_sort(&tvars);
	ft_free(tvars.a, tvars.b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:39:50 by ichouare          #+#    #+#             */
/*   Updated: 2023/02/26 15:04:32 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	**enter_function(t_Bonus *tvars)
{
	char	*buffer;
	char	*str2;
	char	*tmp;

	buffer = (char *)ft_calloc(1, sizeof(char));
	str2 = get_next_line(0);
	while (str2 != NULL)
	{
		check_enter(str2);
		tmp = buffer;
		buffer = ft_strjoin(buffer, str2);
		free(tmp);
		tmp = buffer;
		free(str2);
		buffer = ft_strjoin(buffer, " ");
		free(tmp);
		str2 = get_next_line(0);
	}
	tvars->fcts = ft_split(buffer, ' ');
	free(buffer);
	return (tvars->fcts);
}

void	make_func(t_Bonus *tvars, int *i)
{
	while (tvars->fcts[*i])
	{
		if (ft_strcmp(tvars->fcts[*i], "ra", 2) == 0)
			ra(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[*i], "pa", 2) == 0)
			pa(tvars->a, tvars->b, &tvars->top, &tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "pb", 2) == 0)
			pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "rb", 2) == 0)
			rb(tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "ss", 2) == 0)
			ss(tvars->a, tvars->top, tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "rra", 3) == 0)
			rra(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[*i], "rrb", 3) == 0)
			rrb(tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "rrr", 3) == 0)
			rrr(tvars->a, tvars->top, tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[*i], "sa", 2) == 0)
			sa(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[*i], "sb", 2) == 0)
			sb(tvars->b, tvars->topb);
	*i = *i + 1;
	}
}

void	check_stack(char **str, int *i)
{
	int	j;

	while (str[*i])
	{
		if (ft_strlen(str[*i]) == 1)
		{
			if (str[*i][0] < '0' || str[*i][0] > '9' )
				ft_error("Error\n", 6);
		}
		else
		{
			if (str[*i][0] != '-' && str[*i][0] != '+'
				&& (str[*i][0] < 48 || str[*i][0] > 57))
				ft_error("Error\n", 6);
			j = 1;
			while (str[*i][j])
			{
				if (str[*i][j] < '0' || str[*i][j] > '9')
					ft_error("Error\n", 6);
				j++;
			}
		}
		*i = *i + 1;
	}
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	main(int argc, char **agrv)
{
	int		i;
	t_Bonus	tvars;

	tvars.topb = -1;
	tvars.str = check_parms_checker(argc, agrv);
	check_stack(tvars.str, &i);
	tvars.a = (int *)malloc(i * sizeof(int));
	tvars.b = (int *)malloc(i * sizeof(int));
	if (tvars.a == NULL || tvars.b == NULL)
		return (0);
	i--;
	if (ft_pop(tvars.str, &tvars.a, &tvars.top, i) == 1)
	{
		ft_free(tvars.a, tvars.b);
		ft_error("Error\n", 6);
	}
	check_arrb(&tvars);
	enter_function(&tvars);
	i = 0;
	make_func(&tvars, &i);
	free_string(tvars.fcts);
	check_sort(tvars.a, tvars.top);
	free_string(tvars.str);
	ft_free(tvars.a, tvars.b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:39:50 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 18:01:41 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**enter_function(void)
{
	char	*buffer;
	char	*str2;
	int		sz;

	buffer = (char *)ft_calloc(1, sizeof(char));
	str2 = get_next_line(0);
	while (str2 != NULL)
	{
		if (ft_strcmp(str2, "ra") != 0 && ft_strcmp(str2, "pa") != 0
			&& ft_strcmp(str2, "pb") != 0 && ft_strcmp(str2, "rb") != 0
			&& ft_strcmp(str2, "rb") != 0 && ft_strcmp(str2, "rra") != 0
			&& ft_strcmp(str2, "rrb") != 0 && ft_strcmp(str2, "rrr") != 0
			&& ft_strcmp(str2, "sb") != 0 && ft_strcmp(str2, "ss") != 0
			&& ft_strcmp(str2, "sa") != 0)
		{
			write(1, "Error\n", 7);
			exit(1);
		}
		buffer = ft_strjoin(buffer, str2);
		buffer = ft_strjoin(buffer, " ");
		str2 = get_next_line(0);
	}
	return (ft_split(buffer, ' '));
}

void	make_func(t_Bonus *tvars)
{
	int	i;

	i = 0;
	while (tvars->fcts[i])
	{
		if (ft_strcmp(tvars->fcts[i], "ra") == 0)
			ra(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[i], "pa") == 0)
			pa(tvars->a, tvars->b, &tvars->top, &tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "pb") == 0)
			pb(tvars->a, tvars->b, &tvars->top, &tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "rb") == 0)
			rb(tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "ss") == 0)
			ss(tvars->a, tvars->top, tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "rra") == 0)
			rra(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[i], "rrb") == 0)
			rrb(tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "rrr") == 0)
			rrr(tvars->a, tvars->top, tvars->b, tvars->topb);
		else if (ft_strcmp(tvars->fcts[i], "sa") == 0)
			sa(tvars->a, tvars->top);
		else if (ft_strcmp(tvars->fcts[i], "sb") == 0)
			sb(tvars->b, tvars->topb);
	i++;
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

int	main(int argc, char **agrv)
{
	int		i;
	t_Bonus	tvars;
	int		j;

	tvars.top = -1;
	tvars.topb = -1;
	tvars.str = check_parms(argc, agrv);
	check_stack(tvars.str, &i);
	tvars.a = (int *)malloc(i * sizeof(int));
	tvars.b = (int *)malloc(i * sizeof(int));
	i--;
	ft_pop(tvars.str, &tvars.a, &tvars.top, i);
	if (check_arr(tvars.a, tvars.top) == 0)
	{
		ft_free(tvars.a, tvars.b);
		ft_error("Error\n", 6);
	}
	tvars.fcts = enter_function();
	make_func(&tvars);
	if (check_sort(tvars.a, tvars.top) == 1)
		write(1, "KO\n", 4);
	else
		write(1, "OK\n", 4);
	return (0);
}

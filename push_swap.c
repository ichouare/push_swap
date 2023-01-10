/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:26 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/10 17:51:43 by ichouare         ###   ########.fr       */
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

char	**check_parms(int argc, char **agrv)
{
	char	*args;
	char	**str;
	char	*tmp;
	int		i;

	if (argc == 1)
		ft_error("no parameters are specified\n", 29);
	i = 1;
	args = agrv[i];
	i = 2;
	while (i < argc)
	{
		tmp = args;
		args = ft_strjoin(args, " ");
		if (i != 2)
			free (tmp);
		tmp = args;
		args = ft_strjoin(args, agrv[i]);
		free (tmp);
		i += 1;
	}
	str = ft_split(args, ' ');
	return (str);
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
	if (check_arr(tvars.a, tvars.top) == 0)
	{
		ft_free(tvars.a, tvars.b);
		ft_error("arguments are bigger than integer/duplicates\n", 79);
	}
	ft_sort(&tvars);
	return (0);
}

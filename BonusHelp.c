/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BonusHelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:32:54 by ichouare          #+#    #+#             */
/*   Updated: 2023/03/01 12:07:40 by ichouare         ###   ########.fr       */
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

void	check_str_checker(char **str)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (str[1] == NULL)
	{
		while (i < ft_strlen(str[0]))
		{
			if (str[0][i] < '0' || str[0][i] > '9')
				j = 1;
			i++;
		}
		if (j == 1)
		{
			ft_error("Error", 5);
			exit (0);
		}
		write(1, "OK\n", 2);
		exit (0);
	}
}

char	**check_parms_checker(int argc, char **agrv)
{
	char	*args;
	char	**str;
	char	*tmp;
	int		i;

	if (argc == 1)
		ft_error(NULL, 0);
	i = 1;
	args = agrv[i];
	args = ft_strjoin(args, " ");
	i = 2;
	while (agrv[i])
	{
		tmp = args;
		args = ft_strjoin(args, agrv[i]);
		free (tmp);
		tmp = args;
		args = ft_strjoin(args, " ");
		free (tmp);
		i += 1;
	}
	str = ft_split(args, ' ');
	check_str_checker(str);
	free(args);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:43:33 by ichouare          #+#    #+#             */
/*   Updated: 2023/01/11 17:33:58 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*sort_temp(int *tab, int top)
{
	int	i;
	int	max;
	int	j;
	int	*temp_tab;

	temp_tab = (int *) malloc(top * sizeof(int));
	i = 0;
	while (i++ <= top)
	{
		temp_tab[i] = tab[i];
	}
	i = 1;
	while (i <= top)
	{
		max = temp_tab[i];
		j = i - 1;
		while (j >= 0 && temp_tab[j] > max)
		{
			temp_tab[j + 1] = temp_tab[j];
			j -= 1;
		}
		temp_tab[j + 1] = max;
		i++;
	}
	return (temp_tab);
}

int	check_arr(t_list *tvars)
{
	int	i;
	int	j;

	i = tvars->top;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tvars->a[i] == tvars->a[j] || tvars->a[i] >= 2147483647
				|| tvars->a[i] < -2147483647)
			{
				ft_free(tvars->a, tvars->b);
				ft_error("arguments are bigger than integer/duplicates \n", 47);
			}
			j--;
		}
		i--;
	}
	return (1);
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

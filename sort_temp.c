/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:43:33 by ichouare          #+#    #+#             */
/*   Updated: 2023/02/26 15:04:59 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*sort_temp(int *tab, int top)
{
	int	i;
	int	min;
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
		min = temp_tab[i];
		j = i - 1;
		while (j >= 0 && temp_tab[j] > min)
		{
			temp_tab[j + 1] = temp_tab[j];
			j -= 1;
		}
		temp_tab[j + 1] = min;
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
			if (tvars->a[i] == tvars->a[j])
			{
				ft_free(tvars->a, tvars->b);
				ft_error("arguments are bigger than integer/duplicates\n", 45);
			}
			j--;
		}
		i--;
	}
	return (1);
}

void	check_str(char **str)
{
	size_t i;
	int j;
	
	i = 0;
	j = 0;
	if (str[1] == NULL)
	{
		while(i < ft_strlen(str[0]))
		{
			if (str[0][i] < '0' || str[0][i] > '9')
				j = 1;
			i++;
		}
		if(j == 1)
		{
			ft_error("Error", 5);
			exit(0);
		}
		exit(0);
	}
}

char	**check_parms(int argc, char **agrv)
{
	char	*args;
	char	**str;
	char	*tmp;
	int		i;

	if (argc == 1)
		ft_error("no parameters are specified\n", 28);
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
	check_str(str);
	free(args);
	return (str);
}

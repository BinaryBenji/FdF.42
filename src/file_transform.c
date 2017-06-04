/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:06:11 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/01 14:06:33 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Determine the max x coord, in order to malloc good size
*/

int		determine_eastmax(char *line, t_env *env, int south)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (false_tab(tab) == 1)
		return (-1);
	while (tab[i])
		i++;
	env->eastmax[south] = tablen(tab);
	return (i);
}

/*
**	Malloc and store a line in tab
*/

t_env	work_coords(int fd, t_env *env)
{
	char	*line;
	int		south;

	if (!(env->tab = (int **)malloc(sizeof(int *) * (env->southmax))))
		exiterror();
	if (!(env->eastmax = (int *)malloc(sizeof(int) * (env->southmax))))
		exiterror();
	line = NULL;
	south = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((determine_eastmax(line, env, south)) == -1)
			exiterror();
		if (south != 0)
			if (env->eastmax[south] != env->eastmax[south - 1])
				exiterror();
		if ((env->tab[south] = assign_all_coords(line)) == NULL)
			exiterror();
		south++;
	}
	debugcoords(*env);
	return (*env);
}

/*
**	Print all (debug)
*/

void	debugcoords(t_env env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < env.southmax)
	{
		ft_putstr("Ligne ");
		ft_putnbr(i);
		ft_putstr(" : ");
		while (j < env.eastmax[i])
		{
			ft_putnbr(env.tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}

/*
**	Transforms a line into a tab of int
*/

int		*assign_all_coords(char *line)
{
	char	**tab;
	int		i;
	int		*oneline;
	int		eastmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	eastmax = tablen(tab);
	if (!(oneline = (int *)malloc(sizeof(int) * eastmax)))
		return (NULL);
	while (tab[i] && (i < eastmax))
	{
		oneline[i] = ft_atoi(tab[i]);
		i++;
	}
	return (oneline);
}

/*
**	Error detect
*/

int		false_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
			if (tab[i][j] == '-')
			{
				j++;
				while (tab[i][j] != '\0')
				{
					if (tab[i][j] < '0' || tab[i][j] > '9')
						return (1);
					j++;
				}
			}
			else if (tab[i][j] >= '0' && tab[i][j] <= '9')
				j++;
			else
				return (1);
		i++;
	}
	return (0);
}

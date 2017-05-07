/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:06:11 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 18:06:14 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Determine the max x coord, in order to malloc good size
*/

int 	determine_eastmax(char *line)
{
	int i;
	char **tab;

	i = 0;
	tab = ft_strsplit(line,' ');
	if (false_tab(tab) == 1)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}

/*
**	Malloc and store a line in tab
*/

t_env	work_coords(int fd, t_env env)
{
	char 	*line;
	int 	south;

	if (!(env.tab = (int **)malloc(sizeof(int **))))
		exiterror();
	line = NULL;
	south = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((env.eastmax = determine_eastmax(line)) == -1)
			exiterror();
		if ((env.tab[south] = assign_all_coords(line)) == NULL)
			exiterror();
		south++;
	}
	env.southmax = south;
	//debugcoords(env);
	return (env);
}

/*
**	Print all (debug)
*/

void 	debugcoords(t_env env)
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
		while (j < env.eastmax)
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
	char 	**tab;
	int 	i;
	int 	*oneline;

	if (!(oneline = (int *)malloc(sizeof(int) * ft_strlen(line))))
		return (NULL);
	i = 0;
	tab = ft_strsplit(line, ' ');
	// if (false_tab(tab) == 1)
	// 	return (NULL);
	while (tab[i])
	{
		oneline[i] = ft_atoi(tab[i]);
		i++;
	}
	return (oneline);
}

/*
**	Error detect
*/

int 	false_tab(char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][0] == '-' && tab[i][1] > '0' && tab[i][1] < '9')
			j++;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
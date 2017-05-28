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

t_coords	work_coords(int fd, t_coords coords)
{
	char 	*line;
	int 	south;

	if (!(coords.tab = (int **)malloc(sizeof(int **))))
		exiterror();
	line = NULL;
	south = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((determine_eastmax(line)) == -1)
			exiterror();
		if ((coords.tab[south] = assign_all_coords(line, coords)) == NULL)
			exiterror();
		south++;
	}
	//debugcoords(coords);
	return (coords);
}

/*
**	Print all (debug)
*/

// void 	debugcoords(t_coords coords)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < coords->southmax)
// 	{
// 		ft_putstr("Ligne ");
// 		ft_putnbr(i);
// 		ft_putstr(" : ");
// 		while (j < coords->eastmax)
// 		{
// 			ft_putnbr(coords->tab[i][j]);
// 			ft_putchar(' ');
// 			j++;
// 		}
// 		ft_putstr("\n");
// 		j = 0;
// 		i++;
// 	}
// }

/*
**	Transforms a line into a tab of int
*/

int		*assign_all_coords(char *line, t_coords coords)
{
	char 	**tab;
	int 	i;
	int 	*oneline;
	int 	eastmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	eastmax = tablen(tab);
	if (!(oneline = (int *)malloc(sizeof(int) * eastmax)))
		return (NULL);
	// if (false_tab(tab) == 1)
	// 	return (NULL);
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

int 	false_tab(char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
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
		}
		i++;
		j = 0;
	}
	return (0);
}

int 	tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
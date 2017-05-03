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
**	Malloc and store a line of z coord
*/

t_env	work_coords(int fd, t_env env)
{
	char 	*line;
	int 	south;

	line = NULL;
	south = 0;
	if (!(env.tab = (int **)malloc(sizeof(int**))))
		exiterror();
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((env.eastmax = determine_eastmax(line)) == -1)
			exiterror();
		if (!(env.tab[south] = (int *)malloc(sizeof(int) * env.eastmax)))
			exiterror();
		if ((env.tab[south] = assign_all_coords(line, env)) == NULL)
			exiterror();
		south++;
	}
	env.southmax = south;
	return (env);
}

/*
**	Transforms a line into a tab of int
*/

int		*assign_all_coords(char *line, t_env env)
{
	char 	**tab;
	int 	i;
	int 	*oneline;

	if (!(oneline = (int *)malloc(sizeof(int) * ft_strlen(line))))
		return (NULL);
	i = 0;
	tab = ft_strsplit(line, ' ');
	if (false_tab(tab) == 1)
		return (NULL);
	while(tab[i])
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


/*
**	Gives nb of strings in a tab
*/

// int 	ft_tablen_str(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while (tab[i] != NULL)
// 		i++;
// 	return (i);
// }

/*
**	Print all (debug)
*/

// void	print_coords(t_coord **coords)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	i = 0;
// 	while (1)
// 	{
// 		while (1)
// 		{
// 			printf("x = %d || y = %d || z = %d \n", coords[i][j].x, coords[i][j].y, coords[i][j].z);
// 			j++;
// 			if ((coords[i][j-1].x + 1) != coords[i][j].x)
// 				break;
// 		}
// 		i++;
// 		j = 0;
// 		if ((coords[i-1][j].y + 1) != coords[i][j].y)
// 			break;
// 	}
// }

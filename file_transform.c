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
**	All the coords handling is here.
**	Get a line, allocate a serie of t_coord
**		Then assign all coords with sub function
*/

t_coord		**work_coords(int fd, t_coord **coords)
{
	int		south;
	t_coord **tmpall;
	char *line = NULL;
	
	south = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (!(tmpall[south] = (t_coord*)malloc(sizeof(t_coord*))))
			return (NULL);
		if ((tmpall[south] = assign_all_coords(line, south)) == NULL)
			return (NULL);
		south++;
	}
	return (tmpall);
}

/*
**	Assign the coords given by the file to a tab of t_coord.
*/

t_coord		*assign_all_coords(char *line, int south)
{
	char **tab;
	int i;
	t_coord *aline;

	tab = ft_strsplit(line, ' ');
	if (!(aline = (t_coord*)malloc(sizeof(t_coord) * ft_tablen(tab))))
		return (NULL);
	i = 0;
	while(tab[i] != NULL)
	{
		aline[i].x = i;
		aline[i].y = south;
		aline[i].z = ft_atoi(tab[i]);
		i++;
	}
	return (aline);
}

/*
**	Gives length of a tab 
**	Need to add in libft
*/

int 	ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/*void	print_coords(t_coord **coords)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (coords[i] != N)
	{
		printf("%d %d %d \n", coords[i][j].x, coords[i][j].x, coords[i][j].z)
		j++;

	}

}*/

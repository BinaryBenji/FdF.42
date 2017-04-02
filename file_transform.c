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
	char 	*line = NULL;
	
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
	char 	**tab;
	int 	i;
	t_coord *aline;

	tab = ft_strsplit(line, ' ');
	if (false_tab(tab) == 1)
		return (NULL);
	if (!(aline = (t_coord*)malloc(sizeof(t_coord) * ft_tablen_str(tab))))
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

int 	false_tab(char **tab)
{
	int i;
	int j;
	int moins;

	moins = 0;
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

int 	ft_tablen_str(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/*
**	Print all (debug)
*/

void	print_coords(t_coord **coords)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (1)
	{
		while (1)
		{
			printf("x = %d || y = %d || z = %d \n", coords[i][j].x, coords[i][j].y, coords[i][j].z);
			j++;
			if ((coords[i][j-1].x + 1) != coords[i][j].x)
				break;
		}
		i++;
		j = 0;
		if ((coords[i-1][j].y + 1) != coords[i][j].y)
			break;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:34:47 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 17:34:50 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"


/*
**	Calcul du centre a partir de la taille d'une ligne du fichier
*/

/*
**	Bresenham Algorithm for tracing a line.
*/

void		draw_line(int x1, int x2, int dy1, int dy2, void *mlx, void *win)
{
	int dx;
	int dy;
	int p;
	int end;
	int x;
	int y;

	dx = abs(x1 - x2); //calc
	dy = abs(y1 - y2);
	p = 2 * dy - dx;
	x = (x1 < x2) ? (x1) : (x2);
	y = (x == x1) ? (y1) : (y2);
	end = (x == x1) ? (x2) : (x1);
	while(x < end)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		if(p < 0)
			p = p + 2 * dy;
		else
		{
			y++;
			p = p + 2 * (dy - dx);
		}
		x++;
	}
}

/*
**	All the coords handling is here.
**	We allocate the length of each line in a tab of t_coord.
**		Then we assign each t_coord variable of the tab
*/

t_coord		**work_coords(char *path, t_coord **coords)
{
	int		east;
	int		south;
	char 	*str;

	i = 0;
	while(get_next_line(argv[1]) == 1)
	{
		while (str[east] != '\0')
			east++;
		if (!(coords[north] = (t_coord *)malloc((east)* sizeof(t_coord))))
			return (NULL);
		if ((coords[north] = assign_all_coords(coords, line)) == NULL)
			return NULL;
		north++;
		east = 0;
	}
	return (coords);
}

/*
**	Assign the coords given by the file to a tab of t_coord.
*/

t_coord		*assign_all_coords(char **line, t_coord **coords, int north)
{
	char 	*str;
	char 	tmp[2];
	int 	i;
	int 	j;
	int 	east;

	east = 0;
	i = 0;
	j = 0;
	str = ft_strdup(str);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == ' ')
			NULL;
		else if (ft_isdigit(ft_atoi(str[i])) >= 0)
		{
			if (str[i - 1] == '-')
			{
				tmp[j] = str[i - 1];
				j++;
			}
			tmp[j] = str[i];
			j = 0;
			if (coords[north][east] = assign_one_coord(tmp, coords[north][east], east, i))
				return (NULL);
			east++;
		}
		else
			return (NULL);
		i++;
	}
}

/*
**	Assign the coords given by the file to one t_coord.
*/

t_coord		assign_one_coord(char *tmp, t_coord coord, int east, int i)
{
	if (!(coord = (t_coord)malloc(sizeof(t_coord))))
		return NULL;
	coord->x = east;
	coord->y = north;
	coord->value = ft_atoi(tmp);
	coord->index = i;
	return (coord);
}

/*
**	Error case
*/

void	error(void)
{
	ft_putstr_fd("error\n", 1);
}

/*
**	Usage	
*/

void	usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
}

int main(int argc, char **argc)
{
	void	*mlx;
	void	*win;
	t_coord **coords;

	/*int coordx1 = 450;
	int coordx2 = 50;
	int coordy1 = 799;
	int coordy2 = 200;*/
	if (argc != 2)
		return (usage());
	if ((coords = work_coords(coords)) == NULL)
		return (error());
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "FdF");
	draw_line(coordx1, coordx2, coordy1, coordy2, mlx, win);
	mlx_loop(mlx);
}

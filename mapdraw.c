/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:57:24 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/20 11:57:27 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Bresenham Algorithm for tracing a line.
*/

void		draw_line(int x1, int x2, int y1, int y2, void *mlx, void *win)
{
	int dx;
	int dy;
	int p;
	int end;
	int x;
	int y;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	p = 2 * dy - dx;
	x = (x1 < x2) ? (x1) : (x2);
	y = (x == x1) ? (y1) : (y2);
	end = (x == x1) ? (x2) : (x1);
	while(x < end)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			y++;
			p = p + 2 * (dy - dx);
		}
		x++;
	}
}

void	ft_mapdraw(t_coord **coords, void *mlx, void *win)
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "FdF");
	
	mlx_loop(mlx);
}

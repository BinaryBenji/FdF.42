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

/*void	try_draw_line(int x1, int y1, int x2, int y2, t_coords coords)
{
	int delta_x;
	int delta_y;
	int incr1;
	int incr2;

	delta_x = abs(x2 - x1);
	delta_y = abs(y2 - y1);
	incr1 = (x2 - x1) ? 1 : -1;
	incr2 = (y2 - y1) ? 1 : -1;
	if ((delta_x - delta_y) > 0) 
		pixels(env, 1); 
	else
		pixels(env, 0);
}

void 	pixels(t_env, int decider)
{

}
*/

/*
**	Events
*/

int 	key_pressed(int keycode, t_env env)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

/*
**	Initialize the map which moves according to events
*/

/*void	ft_mapdraw(t_coord **coords, t_env env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "FdF"); // center 600 600 limit 1000 1000 
	total_draw(env, coords);
	mlx_key_hook(env->win, key_pressed, &env);
	mlx_loop(mlx);
}*/
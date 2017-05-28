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

// void 	bresenham(t_env env)
// {
// 	int delta_x;
// 	int delta_y;
// 	int incrx;
// 	int incry;
// 	incrx = (x2 - x1) ? 1 : -1;
// 	incry = (y2 - y1) ? 1 : -1;


// 	delta_x = abs(x2 - x1);
// 	delta_y = abs(y2 - y1);


// }

// void	draw_line(t_env env)
// {
// 	int delta_x;
// 	int delta_y;
	

// 	if ((delta_x - delta_y) > 0) 
// 		pixels(env, 1); 
// 	else
// 		pixels(env, 0);
// }

// void 	pixels(t_env env, int decider)
// {
// 	if (decider == 0)
// 	{

// 	}
// 	else
// 	{

// 	}
// 	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
// }


/*
**	Events
*/

int 	key_pressed(int keycode, t_env env)
{
	if (keycode == 53) // quit
		exit(0);
	// if (keycode == 30) // up
	// { 
	// 	mlx_clear_window(env.mlx, env.win);
	// 	env.z--;
	// }
	// if (keycode == 31) // down
	// {
	// 	mlx_clear_window(env.mlx, env.win);
	// 	env.z++;
	// }
	//total_draw(env);
	return (0);
}


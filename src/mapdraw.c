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
**	Does what it should do :)
*/

void	draw_all_x(t_env *env)
{
	int i;

	i = 0;
	env->turn = 0;
	while (i < env->southmax)
	{
		while (env->turn < env->eastmax[i] - 1)
		{
			env->x1 = env->view_x + (env->turn - i) * env->linesizex;
			env->y1 = env->view_y + (env->turn + i) * env->linesizey
				- (env->tab[i][env->turn] * env->z);
			env->x2 = env->view_x + ((env->turn + 1) - i) * env->linesizex;
			env->y2 = env->view_y + ((env->turn + 1) + i) * env->linesizey
				- (env->tab[i][env->turn + 1] * env->z);
			pixels(env);
			env->turn++;
		}
		i++;
		env->turn = 0;
	}
}

/*
**	Does what it should do :)
*/

void	draw_all_y(t_env *env)
{
	int i;

	i = 0;
	env->turn = 0;
	while (i < env->southmax - 1)
	{
		while (env->turn < env->eastmax[i])
		{
			env->x1 = env->view_x + (env->turn - i) * env->linesizex;
			env->y1 = env->view_y + (env->turn + i) * env->linesizey
				- (env->tab[i][env->turn] * env->z);
			env->x2 = env->view_x + ((env->turn) - (i + 1)) * env->linesizex;
			env->y2 = env->view_y + ((env->turn) + (i + 1)) * env->linesizey
				- (env->tab[i + 1][env->turn] * env->z);
			pixels(env);
			env->turn++;
		}
		i++;
		env->turn = 0;
	}
}

/*
**	Positive case (dx > dy)
*/

void	positive(t_env *env)
{
	int err;
	int i;

	i = 0;
	err = env->dx / 2;
	while (i < env->dx)
	{
		env->x1 += env->incrx;
		err += env->dy;
		if (err > env->dx)
		{
			err -= env->dx;
			env->y1 += env->incry;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
		i++;
	}
}

/*
**	Negative case (dx < dy)
*/

void	negative(t_env *env)
{
	int err;
	int i;

	i = 0;
	err = env->dy / 2;
	while (i < env->dy)
	{
		env->y1 += env->incry;
		err += env->dx;
		if (err > env->dy)
		{
			err -= env->dy;
			env->x1 += env->incrx;
		}
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
		i++;
	}
}

/*
**	Bresenham Algorithm
**	Define values of incr, in order to obtain direction coefficients.
**	Then draw in function of results.
*/

void	pixels(t_env *env)
{
	env->incrx = (env->x2 > env->x1) ? 1 : -1;
	env->incry = (env->y2 > env->y1) ? 1 : -1;
	env->dx = abs(env->x2 - env->x1);
	env->dy = abs(env->y2 - env->y1);
	if (env->dx > env->dy)
	{
		positive(env);
	}
	else
	{
		negative(env);
	}
	mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, env->color);
	mlx_pixel_put(env->mlx, env->win, env->x2, env->y2, env->color);
}

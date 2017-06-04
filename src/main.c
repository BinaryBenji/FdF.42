/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:34:47 by bzmuda            #+#    #+#             */
/*   Updated: 2017/06/01 13:32:10 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Draws x and y lines.
*/

void	draw(t_env *env)
{
	draw_all_x(env);
	draw_all_y(env);
}

/*
**	Gives basic parameters to struct
*/

t_env	init_map(t_env *env)
{
	env->height = 1200;
	env->width = 1200;
	env->color = 0x00FFFFFF;
	env->linesizex = 32;
	env->linesizey = 16;
	env->z = 2;
	env->view_x = 400;
	env->view_y = 400;
	return (*env);
}

/*
**	Loop of draw & events
*/

void	ft_map(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "FdF");
	draw(env);
	mlx_key_hook(env->win, key_pressed, env);
	mlx_loop(env->mlx);
}

/*
**	Gives number of lines, in order to do correct malloc
*/

void	calc_southmax(int fd, t_env *env)
{
	char	*line;
	int		south;

	south = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
		south++;
	env->southmax = south;
}

/*
**	Main
*/

int		main(int argc, char **argv)
{
	t_env		env;
	int			fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	init_map(&env);
	calc_southmax(fd, &env);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	work_coords(fd, &env);
	ft_map(&env);
	return (0);
}

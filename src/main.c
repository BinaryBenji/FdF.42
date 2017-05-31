/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:34:47 by bzmuda            #+#    #+#             */
/*   Updated: 2017/05/28 16:56:46 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_env 	init_map(t_env *env)
{
	env->height = 1200;
	env->width = 1200;
	env->color = 0x00FFFFFF;
	env->linesizex = 16;
	env->linesizey = 32;
	env->z = 0;
	return (*env);
}

void 	ft_map(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height, "FdF");
	draw(env);
	mlx_key_hook(env->win, key_pressed, env);
	mlx_loop(env->mlx);
}

void 	calc_southmax(int fd, t_env *env)
{
	char 	*line;
	int 	south;

	south = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
		south++;
	env->southmax = south;
}

int 	main(int argc, char **argv)
{
	t_env		env;
	int 		fd;

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

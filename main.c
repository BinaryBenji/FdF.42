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

#include "fdf.h"


t_env init_map(t_env env)
{
	env.height = 1200;
	env.width = 1200;
	return (env);
}

int main(int argc, char **argv)
{
	t_coord **coords;
	t_env	env;
	int 	fd;

	if (argc != 2)
		return (usage());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	coords = work_coords(fd);
	if (coords == NULL)
		return (error());
	close(fd);
	env = init_map(env);


	//ft_mapdraw(env, coords);
	//print_coords(coords);
	return (0);
}
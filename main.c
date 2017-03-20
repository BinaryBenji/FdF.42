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

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_coord **coords;
	int 	fd;

	if (argc != 2)
		return (usage());
	fd = open(argv[1], O_RDONLY);
	coords = work_coords(fd, coords);
	if (coords == NULL)
		return (error());
	//print_coords(coords);
	ft_mapdraw(coords, mlx, win);
	return (0);
}
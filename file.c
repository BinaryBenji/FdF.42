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
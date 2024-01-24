/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:32:22 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 14:43:03 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "valid.h"

static t_bool	input_ambient(char *line, t_scene **scene)
{
	line++;
	(*scene)->ambient = ambient(ddouble(&line),
			vdiv(vvector(&line), 255));
	return (TRUE);
}

static t_bool	input_element(char *line, t_scene **scene)
{
	while (check_whitespace(line))
		line++;
	if (line[0] == 'A' && input_ambient(line, scene))
		return (TRUE);
	else if (line[0] == 'C' && input_camera(line, scene))
		return (TRUE);
	else if (line[0] == 'L' && input_light(line, scene))
		return (TRUE);
	else if (line[0] == 's' && line[1] == 'p' && input_sphere(line, scene))
		return (TRUE);
	else if (line[0] == 'p' && line[1] == 'l' && input_plane(line, scene))
		return (TRUE);
	else if (line[0] == 'c' && line[1] == 'y' && input_cylinder(line, scene))
		return (TRUE);
	return (FALSE);
}

static t_bool	init_scene(int fd, t_scene **scene)
{
	char		*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!check_empty_line(line) && !input_element(line, scene))
		{
			print_error("Failed malloc.");
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (FALSE);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (TRUE);
}

t_bool	create_scene(t_scene **scene, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (FALSE);
	}
	*scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!(*scene))
	{
		print_error("Failed malloc.");
		close(fd);
		return (FALSE);
	}
	(*scene)->canvas = canvas(CANVAS_WIDTH, CANVAS_HEIGHT);
	if (!init_scene(fd, scene))
	{
		destroy_scene(scene);
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

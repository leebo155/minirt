/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:21:10 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/18 12:45:24 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

static t_bool	check_extension(char *file)
{
	size_t	filename_length;

	filename_length = ft_strlen(file);
	if (filename_length < 3)
		return (FALSE);
	if (file[filename_length - 3] != '.'
		|| file[filename_length - 2] != 'r'
		|| file[filename_length - 1] != 't')
	{
		printf("Error: File extension is not .rt\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	check_element(char *line, t_checklist *checklist)
{
	while (check_whitespace(line))
		line++;
	if (line[0] == 'A' && check_ambient(line))
		return (++(checklist->ambient));
	else if (line[0] == 'C' && check_camera(line))
		return (++(checklist->camera));
	else if (line[0] == 'L' && check_light(line))
		return (++(checklist->light));
	else if (line[0] == 's' && line[1] == 'p' && check_sphere(line))
		return (TRUE);
	else if (line[0] == 'p' && line[1] == 'l' && check_plane(line))
		return (TRUE);
	else if (line[0] == 'c' && line[1] == 'y' && check_cylinder(line))
		return (TRUE);
	return (FALSE);
}

static t_bool	check_format(int fd, t_checklist *checklist)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		if (!check_empty_line(line) && !check_element(line, checklist))
		{
			printf("Error: %d line does not fit the format.\n", rows);
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

static void	init_checklist(t_checklist *checklist)
{
	checklist->camera = 0;
	checklist->ambient = 0;
	checklist->light = 0;
}

t_bool	check_valid(char *file)
{
	int			fd;
	t_checklist	checklist;

	init_checklist(&checklist);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (FALSE);
	}
	if (!check_extension(file) || !check_format(fd, &checklist))
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	if (checklist.camera != 1 || checklist.ambient != 1
		|| checklist.light > 1)
	{
		printf("Error: Camera/ambient/light should be declared one each.\n");
		return (FALSE);
	}
	return (TRUE);
}

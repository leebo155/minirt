/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:22 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 14:28:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "valid.h"

t_bool	input_camera(char *line, t_scene **scene)
{
	line++;
	(*scene)->camera = camera(&(*scene)->canvas,
			vvector(&line),
			vvector(&line),
			ddouble(&line));
	return (TRUE);
}

t_bool	input_light(char *line, t_scene **scene)
{
	t_light		*lght;
	t_object	*obj;

	line++;
	lght = light(vvector(&line),
			ddouble(&line),
			vdiv(vvector(&line), 255));
	if (!lght)
		return (FALSE);
	obj = object(LIGHT, lght, color3(0, 0, 0));
	if (!obj)
	{
		free(lght);
		return (FALSE);
	}
	if ((*scene)->light)
		obj_add(&(*scene)->light, obj);
	else
		(*scene)->light = obj;
	return (TRUE);
}

t_bool	input_sphere(char *line, t_scene **scene)
{
	t_sphere	*sp;
	t_object	*obj;

	line++;
	line++;
	sp = sphere(vvector(&line),
			ddouble(&line));
	if (!sp)
		return (FALSE);
	obj = object(SP, sp, vdiv(vvector(&line), 255));
	if (!obj)
	{
		free(sp);
		return (FALSE);
	}
	if ((*scene)->world)
		obj_add(&(*scene)->world, obj);
	else
		(*scene)->world = obj;
	return (TRUE);
}

t_bool	input_plane(char *line, t_scene **scene)
{
	t_plane		*pl;
	t_object	*obj;

	line++;
	line++;
	pl = plane(vvector(&line),
			vvector(&line));
	if (!pl)
		return (FALSE);
	obj = object(PL, pl, vdiv(vvector(&line), 255));
	if (!obj)
	{
		free(pl);
		return (FALSE);
	}
	if ((*scene)->world)
		obj_add(&(*scene)->world, obj);
	else
		(*scene)->world = obj;
	return (TRUE);
}

t_bool	input_cylinder(char *line, t_scene **scene)
{
	t_cylinder		*cy;
	t_object		*obj;

	line++;
	line++;
	cy = cylinder(vvector(&line),
			vvector(&line),
			ddouble(&line),
			ddouble(&line));
	if (!cy)
		return (FALSE);
	obj = object(CY, cy, vdiv(vvector(&line), 255));
	if (!obj)
	{
		free(cy);
		return (FALSE);
	}
	if ((*scene)->world)
		obj_add(&(*scene)->world, obj);
	else
		(*scene)->world = obj;
	return (TRUE);
}

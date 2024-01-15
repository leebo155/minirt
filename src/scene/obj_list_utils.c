/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:09:45 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 13:52:31 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	obj_add(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_object	*obj_last(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	destroy_scene(t_scene **scene)
{
	t_object	*tmp;
	t_object	*tail;

	tail = (*scene)->world;
	while (tail)
	{
		tmp = tail;
		tail = tail->next;
		free(tmp->element);
		free(tmp);
	}
	tail = (*scene)->light;
	while (tail)
	{
		tmp = tail;
		tail = tail->next;
		free(tmp->element);
		free(tmp);
	}
	free(*scene);
}

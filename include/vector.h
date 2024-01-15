/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:49:53 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/11 14:11:29 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include "structures.h"

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
t_vec3		vvplus(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdplus(t_vec3 vec, double x, double y, double z);
t_vec3		vvminus(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdminus(t_vec3 vec, double x, double y, double z);
t_vec3		vdmult(t_vec3 vec, double t);
t_vec3		vvmult(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdiv(t_vec3 vec, double t);
double		vdot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);
double		vec_pow(t_vec3 vec);
double		vec_length(t_vec3 vec);

#endif

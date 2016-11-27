/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:16:50 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 10:22:27 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vertex	normalise_point(t_vertex *p1, t_vertex *p2, t_vertex *p3)
{
	t_vertex	u;
	t_vertex	v;
	t_vertex	normal;
	float		temp;

	u.x = p2->x - p1->x;
	u.y = p2->y - p1->y;
	u.z = p2->z - p1->z;
	v.x = p3->x - p1->x;
	v.y = p3->y - p1->y;
	v.z = p3->z - p1->z;
	normal.x = (u.y * v.z) - (u.z * v.y);
	normal.y = (u.z * v.x) - (u.x * v.z);
	normal.z = (u.x * v.y) - (u.y * v.x);
	temp = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
	normal.x = (normal.x / temp) / 10;
	normal.y = (normal.y / temp) / 10;
	normal.z = (normal.z / temp) / 10;
	//    printf("NORMALS\n");
	//    printf("x = %f\n", normal.x);
	//    printf("y = %f\n", normal.y);
	//    printf("z = %f\n", normal.z);
	return (normal);
	//glNormal3f(normal.x, normal.y, normal.z);
}

void	normalise(void)
{
	int		q;
	float	u[1][3];
	float	v[1][3];
	float	temp;
	int		i;
	int		j;

	i = 1;
	j = 2;
	q = 0;
	if (!(g_normals = (t_vertex *)malloc(sizeof(t_vertex) * g_num_vertex)))
		error_quit("Malloc error");
	ft_bzero(g_normals, sizeof(t_vertex) * (int)g_num_vertex);
	while (q < g_num_vertex)
	{
		if (i == g_num_vertex)
			i = 0;
		if (j == g_num_vertex)
			j = 0;
		u[0][0] = g_vertecies[q]->x - g_vertecies[i]->x;
		u[0][1] = g_vertecies[q]->y - g_vertecies[i]->y;
		u[0][2] = g_vertecies[q]->z - g_vertecies[i]->z;
		v[0][0] = g_vertecies[q]->x - g_vertecies[j]->x;
		v[0][1] = g_vertecies[q]->y - g_vertecies[j]->y;
		v[0][2] = g_vertecies[q]->z - g_vertecies[j]->z;
		g_normals[q].x = (u[0][1] * v[0][2]) - (u[0][2] * v[0][1]);
		g_normals[q].y = (u[0][2] * v[0][0]) - (u[0][0] * v[0][2]);
		g_normals[q].z = (u[0][0] * v[0][1]) - (u[0][1] * v[0][0]);
		temp = sqrt((g_normals[q].x * g_normals[q].x + g_normals[q].y * g_normals[q].y + g_normals[q].z * g_normals[q].z));
		g_normals[q].x = g_normals[q].x / temp;
		g_normals[q].y = g_normals[q].y / temp;
		g_normals[q].z = g_normals[q].z / temp;
		//printf("normal: %f, %f, %f\n", g_normals[q].x, g_normals[q].y, g_normals[q].z);
        q++;
		i++;
		j++;
	}
}

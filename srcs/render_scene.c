/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:39:22 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 10:21:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

GLfloat light_diffuse[] = {6.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */

void	render_vertex(void)
{
	t_list			*list;
	t_vertex		*ver;
	char			type;
	unsigned int	k;

	list = g_lst;
	glBegin(GL_POLYGON);
	k = 0;
	while (list && (++k + 1))
	{
		ft_memcpy(&type, list->content, 1);
		if (type == TYPE_VERTEX)
		{
			glColor3f(((k) % 3), ((k + 1) % 3), ((k + 2) % 3));
			ver = (t_vertex *)list->content;
			glVertex4f(ver->x, ver->y, ver->z, ver->w);
		}
		list = list->next;
	}
	glEnd();
}

/*
** To Restore the Hardcoded version, replace render_vertex with:
**	glBegin(GL_POLYGON);
**	glVertex3f(-2.0f, -2.0f, 0.0f);
**	glVertex3f(2.0f, 0.0f, 0.0f);
**	glVertex3f(0.0f, 2.0f, 0.0f);
**	glVertex3f(3.0f, 3.0f, 3.0f);
**	glVertex3f(2.0f, 0.0f, 0.0f);
**	glEnd();
*/

void	computePos(float g_delta_move)
{
	g_x += g_delta_move * g_lx * 0.1f;
	g_z += g_delta_move * g_lz * 0.1f;
}

void	computeDir(float g_delta_angle)
{
	g_angle += g_delta_angle;
	g_lx = sin(g_angle);
	g_lz = -cos(g_angle);
}

void	render_scene(void)
{
	t_list		*k;
	t_face		*face;
	t_vertex	normal;
	int			q = 0;
	char		tmp;

	if (g_delta_move)
		computePos(g_delta_move);
	if (g_delta_angle)
		computeDir(g_delta_angle);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Color and Depth Buffers
	glLoadIdentity(); // Reset transformations
	//gluLookAt(g_x, 1.0f, g_z, g_x + g_lx, 1.0f, g_z + g_lz,	0.0f, 1.0f, 0.0f); // Set the camera
//	gluPerspective(g_keyhook.zoom, g_keyhook.ratio, 0.1f, 100.0f);
	gluLookAt(0.0f, 0.0f, g_keyhook.zoom, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f);
	//eye, center, up is in positive y direction.
	glColor3f(g_red, g_blue, g_green);
	glRotatef(g_angle, g_centerpoint.center.x, g_centerpoint.center.y, g_centerpoint.center.z);
	k = g_lst;
	while (k != NULL)
	{
		if (k->content)
			ft_memcpy(&tmp, k->content, 1);
		if (tmp == TYPE_FACE)
		{
			face = (t_face *)k->content;
			glBegin((g_keyhook.wire) ? ((face->w) ? ((face->u) ? GL_POLYGON : GL_QUADS) : GL_TRIANGLES) : GL_LINES);
			normal = normalise_point(g_vertecies[face->x - 1], g_vertecies[face->y - 1], g_vertecies[face->z - 1]);
			glNormal3f(normal.x, normal.y, normal.z);
			glVertex3f(g_vertecies[face->x - 1]->x, g_vertecies[face->x - 1]->y, g_vertecies[face->x - 1]->z);
			glVertex3f(g_vertecies[face->y - 1]->x, g_vertecies[face->y - 1]->y, g_vertecies[face->y - 1]->z);
			glVertex3f(g_vertecies[face->z - 1]->x, g_vertecies[face->z - 1]->y, g_vertecies[face->z - 1]->z);
			if (face->w)
				glVertex3f(g_vertecies[face->w - 1]->x, g_vertecies[face->w - 1]->y, g_vertecies[face->w - 1]->z);
			if (face->w && face->u)
				glVertex3f(g_vertecies[face->u - 1]->x, g_vertecies[face->u - 1]->y, g_vertecies[face->u - 1]->z);
			if (face->w && face->u && face->v)
				glVertex3f(g_vertecies[face->v - 1]->x, g_vertecies[face->v - 1]->y, g_vertecies[face->v - 1]->z);
			if (face->w && face->u && face->v && face->o)
				glVertex3f(g_vertecies[face->o - 1]->x, g_vertecies[face->o - 1]->y, g_vertecies[face->o - 1]->z);
			if (face->w && face->u && face->v && face->o && face->p)
				glVertex3f(g_vertecies[face->p - 1]->x, g_vertecies[face->p - 1]->y, g_vertecies[face->p - 1]->z);
			glEnd();
		}
		k = k->next;
		q++;
	}
	g_angle += 0.5f;
	glutSwapBuffers();
}

void	initGL(void)
{
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);  /* Use depth buffering for hidden surface elimination. */
	glMatrixMode(GL_PROJECTION);  /* Setup the view of the cube. */
	glMatrixMode(GL_MODELVIEW);
}

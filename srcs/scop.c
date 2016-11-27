/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:40:14 by khansman          #+#    #+#             */
/*   Updated: 2016/11/27 11:01:34 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/scop.h"

void	init_globals(void)
{
	g_keyhook.zoom = 10.0f;
	g_keyhook.wire = 1;
	g_keyhook.eyex = 0.0f;
	g_keyhook.eyey = 0.0f;
	g_keyhook.centerx = 0.0f;
	g_keyhook.centery = 0.0f;
	g_keyhook.centerz = 0.0f;
	centerpoint();
}

int		main(int ac, char **av)
{
	read_obj(ac, av);
	set_vertix_arr();
	init_globals();
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Scop");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	init_gl();
	glutKeyboardFunc(process_normal_keys);
	glutSpecialFunc(process_special_keys);
	glutSpecialFunc(press_key);
	glutSpecialUpFunc(release_key);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return (1);
}

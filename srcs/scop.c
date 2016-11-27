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

int		main(int ac, char **av)
{
	g_keyhook.zoom = 10.0f;
	read_obj(ac, av);//incomplete
	set_vertix_arr();
	g_keyhook.wire = 1;
	g_keyhook.eyex = 0.0f;
	g_keyhook.eyey = 0.0f;
	g_keyhook.centerx = 0.0f;
	g_keyhook.centery = 0.0f;
	g_keyhook.centerz = 0.0f;
	//	g_keyhook.ratio = 720.0 * 1.0 / 720.0;
	centerpoint();
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Scop");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	initGL();	
	glutKeyboardFunc(process_normal_keys);
	glutSpecialFunc(process_special_keys);
	glutSpecialFunc(pressKey);
	//glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	glEnable(GL_DEPTH_TEST);// added for snow men
	//mlx_hook(env.window->mlx_window, 17, 0L, &close_window, &env);
	//glutWMCloseFunc(); use for closing window with click event
	glutMainLoop();
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:40:14 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:40:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/scop.h"

int		main(int ac, char **av)
{
	read_obj(ac, av);//incomplete
	//print_list(g_lst);//debug
	set_vertix_arr();
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Scop");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	glutKeyboardFunc(process_normal_keys);
	glutSpecialFunc(process_special_keys);
	glEnable(GL_DEPTH_TEST);// added for snow men
	//mlx_hook(env.window->mlx_window, 17, 0L, &close_window, &env);
	//glutWMCloseFunc(); use for closing window with click event
	glutMainLoop();
	return (1);
}

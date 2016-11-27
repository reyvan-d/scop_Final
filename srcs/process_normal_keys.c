/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_normal_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:38:30 by khansman          #+#    #+#             */
/*   Updated: 2016/11/27 12:10:32 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	process_normal_keys(unsigned char key, int x, int y)
{
	static int		mod;

	mod = glutGetModifiers();
	(void)x;
	(void)y;
	if (key == KEY_ESC)
		exit_prog();
	else if (key == 'r')
		g_red = (mod == GLUT_ACTIVE_ALT) ? 0.0 : 1.0;
	key == 'a' && (g_centerpoint.center.x += .5);
	key == 'q' && (g_centerpoint.center.x -= .5);
	key == 'w' && (g_centerpoint.center.y += .5);
	key == 's' && (g_centerpoint.center.y -= .5);
	key == 'e' && (g_centerpoint.center.z += .5);
	key == 'd' && (g_centerpoint.center.z -= .5);
	if (key == 'f')
		g_keyhook.wire = (g_keyhook.wire) ? 0 : 1;
	key == 'm' && (g_keyhook.zoom -= 1.0);
	key == 'n' && (g_keyhook.zoom += 1.0);
	key == '8' && (g_keyhook.centery -= .3);
	key == '2' && (g_keyhook.centery += .3);
	key == '4' && (g_keyhook.centerx += .3);
	key == '6' && (g_keyhook.centerx -= .3);
}

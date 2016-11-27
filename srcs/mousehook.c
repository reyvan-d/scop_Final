/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:49:17 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 17:49:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	mouse_button(int button, int state, int x, int y)
{
	(void)y;
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			g_angle -= g_delta_angle;
			g_xorigin = -1;
		}
		else
			g_xorigin = x;
	}
}

void	mouse_move(int x, int y)
{
	(void)y;
	if (g_xorigin >= 0)
	{
		g_delta_angle = (x - g_xorigin) * 0.01f;
		g_lx = sin(g_angle + g_delta_angle);
		g_lz = -cos(g_angle + g_delta_angle);
	}
}

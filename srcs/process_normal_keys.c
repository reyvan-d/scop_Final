/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_normal_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:38:30 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:38:39 by khansman         ###   ########.fr       */
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
	{
		if (mod == GLUT_ACTIVE_ALT)
			g_red = 0.0;
		else
			g_red = 1.0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 09:07:47 by khansman          #+#    #+#             */
/*   Updated: 2016/11/26 09:07:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static char	determine_set(char *str)
{
	int		k;
	char	l;
	char	result;

	k = -1;
	l = 0;
	result = 0;
	while (str[++k])
	{
		if (str[k] == '/')
			l++;
		else if (l == 0 && ft_isdigit(str[k]))
			result |= F_VERTEX;
		else if (l == 1 && ft_isdigit(str[k]))
			result |= F_TEXTURE;
		else if (l == 2 && ft_isdigit(str[k]))
			result |= F_NORMAL;
	}
	return (result);
}

static void	store_f_piece(t_face *face, char pos, char type, float num)
{
	if (pos == 1 && type == 1)
		face->x = num;
	else if (pos == 2 && type == 1)
		face->y = num;
	else if (pos == 3 && type == 1)
		face->z = num;
	else if (pos == 1 && type == 2)
		face->t_x = num;
	else if (pos == 2 && type == 2)
		face->t_y = num;
	else if (pos == 3 && type == 2)
		face->t_z = num;
	else if (pos == 1 && type == 3)
		face->n_x = num;
	else if (pos == 2 && type == 3)
		face->n_y = num;
	else if (pos == 3 && type == 3)
		face->n_z = num;
}

static void	store_f_part(t_face *face, char *part, char pos)
{
	char		**sub_parts;

	sub_parts = ft_strsplit(part, '/');
	if ((F_VERTEX & face->set) && sub_parts[0] != NULL)
	{
		store_f_piece(face, pos, 1, atof(sub_parts[0]));
		if ((F_TEXTURE & face->set) && sub_parts[1] != NULL)
		{
			store_f_piece(face, pos, 2, atof(sub_parts[1]));
			if ((F_NORMAL & face->set) && sub_parts[2] != NULL)
				store_f_piece(face, pos, 3, atof(sub_parts[2]));
		}
		else if ((F_NORMAL & face->set) && sub_parts[1])
			store_f_piece(face, pos, 3, atof(sub_parts[1]));
	}
	else
		error_quit("Error: unsupported format. A face must contain vertexes");
	ft_free_2d_array(&sub_parts);
}

void		store_face(char *line, t_list **pos)
{
	t_face		face;
	char		**parts;

	ft_bzero(&face, sizeof(t_face));
	parts = ft_strsplit(line, ' ');
	if (parts[1] == NULL || parts[2] == NULL || parts[3] == NULL)
		error_quit("Error: Invalid face");
	face.type = TYPE_FACE;
	face.set = determine_set(parts[1]);
	store_f_part(&face, parts[1], 1);
	store_f_part(&face, parts[2], 2);
	store_f_part(&face, parts[3], 3);
	face.w = (parts[4] != NULL) ? atof(parts[4]) : 1.0f;
	ft_free_2d_array(&parts);
	store_struct((void const *)&face, sizeof(t_face), pos);
}

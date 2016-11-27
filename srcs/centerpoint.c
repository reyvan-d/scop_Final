#include "../includes/scop.h"

void	centerpoint(void)
{
	static int	b;
	t_vertex	*t;
	t_list		*l;
	char		c;

	l = g_lst;
	while (l)
	{
		if (l->content)
		{
			ft_memcpy(&c, l->content, 1);
			if (c == TYPE_VERTEX)
			{
				t = (t_vertex *)l->content;
				if (!b && ++b)
				{
					g_centerpoint.min = vertex_create(t->x, t->y, t->z, t->w);
					g_centerpoint.max = vertex_create(t->x, t->y, t->z, t->w);
				}
				else if (b)
				{
					if (t->x < g_centerpoint.min.x)
						g_centerpoint.min.x = t->x;
					else if (t->x > g_centerpoint.max.x)
						g_centerpoint.max.x = t->x;
					if (t->y < g_centerpoint.min.y)
						g_centerpoint.min.y = t->y;
					else if (t->y > g_centerpoint.max.y) 							g_centerpoint.max.y = t->y;
					if (t->z < g_centerpoint.min.z)
						g_centerpoint.min.z = t->z;
					else if (t->z > g_centerpoint.max.z)							g_centerpoint.max.z = t->z;
				}
			}
		}
		l = l->next;
	}
	g_centerpoint.center.x = (int)(g_centerpoint.min.x + g_centerpoint.max.x) >> 1;
	g_centerpoint.center.y = (int)(g_centerpoint.min.y + g_centerpoint.max.y) >> 1;
	g_centerpoint.center.z = (int)(g_centerpoint.min.z + g_centerpoint.max.z) >> 1;
}

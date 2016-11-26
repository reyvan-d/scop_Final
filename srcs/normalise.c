void    normalise(void)
{
    int     q;
    float   u[1][3];
    float   v[1][3];
    float   temp;
	int		i;
	int		j;

	i = 1;
	j = 2;
    q = 1;
    if (!(g_normals = (t_vertex *)malloc(sizeof(t_vertex) * (int)g_vertecies[0]))
        error_quit("Malloc error");
    ft_bzero(g_vertecies, sizeof(t_vertex) * (int)g_vertecies[0]);
    while (q < g_vertecies[0])
    {
		if (i == g_vertecies[0])
			i = 0;
		if (j == g_vertecies[0])
			j = 0;
        u[0][0] = g_vertecies[q]->x - g_vertecies[i]->x;
        u[0][1] = g_vertecies[q]->y - g_vertecies[i]->y;;
        u[0][2] = g_vertecies[q]->z - g_vertecies[i]->z;
        v[0][0] = g_vertecies[q]->x - g_vertecies[j]->x;;
        v[0][1] = g_vertecies[q]->y - g_vertecies[j]->y;;
        v[0][2] = g_vertecies[q]->z - g_vertecies[j]->z;;
        g_normals[q]->x = (u[0][1] * v[0][2]) - (u[0][2] * v[0][1]);
        g_normals[q]->y = (u[0][2] * v[0][0]) - (u[0][0] * v[0][2]);
        g_normals[q]->z = (u[0][0] * v[0][1]) - (u[0][1] * v[0][0]);
		temp = sqrt((g_normals[q]->x * g_normals[q]->x + g_normals[q]->y * g_normals[q]->y + g_normals[q]->z * g_normals[q]->z));
		g_normals[q]->x = g_normals[q]->x / temp;
		g_normals[q]->y = g_normals[q]->y / temp;
		g_normals[q]->z = g_normals[q]->z / temp;
		printf("normal: %f, %f, %f\n", g_normals[q]->x, g_normals[q]->y, g_normals[q]->z);
        q++;
		i++;
		j++;
    }
}
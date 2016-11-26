/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:32:03 by khansman          #+#    #+#             */
/*   Updated: 2016/11/24 10:32:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** ----------\
** Includes   |
** ----------/
*/

# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
# else
#  include <GL/gl.h>
#  include <GL/glut.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
//# include <libc.h>

# include "../libft/includes/libft.h"

/*
** # include "../minilibx_macos/mlx.h"
** # include "../minilibx_macos/mlx_int.h"
** # include "../minilibx_macos/mlx_new_window.h"
** # include "../minilibx_macos/mlx_opengl.h"
*/

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Keys
*/
# define KEY_ESC   27

/*
** Objects
*/
# define TYPE_VERTEX  1
# define TYPE_TEXTURE 2
# define TYPE_NORMAL  3
# define TYPE_FACE    4
# define TYPE_GROUP   5
# define TYPE_OBJNAME 6
# define TYPE_MTL     7
# define TYPE_MTLFILE 8
# define TYPE_SMOOTH  9
# define TYPE_PSPACE 10

# define F_VERTEX     0b00000001
# define F_TEXTURE    0b00000010
# define F_NORMAL     0b00000100

/*
** Other
*/
# define BASE_STR2 char *base = "0123456789abcdef";

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_vertex
{
	char			type;
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vertex;

typedef struct		s_vertex2
{
	char			type;
	float			u;
	float			v;
	float			w;
}					t_vertex2;

typedef struct		s_face
{
	char			type;
	float			x;
	float			y;
	float			z;
	float			w;
	float			t_x;
	float			t_y;
	float			t_z;
	float			n_x;
	float			n_y;
	float			n_z;
	char			set;
}					t_face;

typedef struct		s_matrix
{
	unsigned int	x;
	unsigned int	y;
	int				**matrix;
}					t_matrix;

typedef struct		s_mat_mul
{
	unsigned int	c;
	unsigned int	d;
	unsigned int	k;
	int				sum;
	struct s_matrix	multiply;
}					t_mat_mul;

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef MAIN_FILE

float				g_red = 1.0;
float				g_blue = 1.0;
float				g_green = 1.0;
float				g_angle = 0;
float				g_lx = 0.0f;
float				g_lz = -1.0f;
float				g_x = 0.0f;
float				g_z = 5.0f;
float				g_deltaAngle = 0.0f;
float				g_deltaMove = 0;
t_list				*g_lst = NULL;
t_vertex			**g_vertecies = NULL;
t_vertex			*g_normals = NULL;
# else

extern float		g_red;
extern float		g_blue;
extern float		g_green;
extern float		g_angle;
extern float		g_lx;
extern float		g_lz;
extern float		g_x;
extern float		g_z;
extern float		g_deltaAngle;
extern float		g_deltaMove;
extern t_list		*g_lst;
extern t_vertex		**g_vertecies;
extern t_vertex		*g_normals;
# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** change_size.c
*/
void				change_size(int w, int h);
/*
** count_elements.c
*/
int					count_elements(char type);
/*
** exit_prog.c
*/
void				exit_prog(void);
/*
** error_quit.c
*/
void				error_quit(char *message);
/*
** free_lst.c
*/
int					free_lst(t_list *list);
int					safe_free_lst(t_list **list);
int					safe_free(void **item);
/*
** ft_atof.c
*/
float				ft_atof(const char *str);
/*
** ft_print_memory.c
*/
void				print_hex(unsigned char num);
void				ft_print_memory(const void *addr, size_t size);
/*
** init_glut.c
*/
void				init_glut(int ac, char **av);
/*
** matrix_add.c
*/
t_matrix			matrix_add(t_matrix first, t_matrix second);
/*
** matrix_create.c
*/
t_matrix			matrix_create(unsigned int x, unsigned int y);
/*
** matrix_destroy.c
*/
int					matrix_destroy(t_matrix matrix);
t_matrix			matrix_clear(t_matrix matrix);
/*
** matrix_identity.c
*/
t_matrix			matrix_identity(unsigned int size);
/*
** matrix_multiply.c
*/
t_matrix			matrix_multiply(t_matrix first, t_matrix second);
/*
** matrix_sub.c
*/
t_matrix			matrix_sub(t_matrix first, t_matrix second);
/*
** matrix_transpose.c
*/
t_matrix			matrix_transpose(t_matrix source);
/*
** normalise.c
*/
void				normalise(void);
/*
** print_list.c
*/
void				print_vetex(t_vertex *vertex);
void				print_face(t_face *face);
void				print_list_details(t_list *pos, unsigned int k);
void				print_list(t_list *list);
/*
** process_normal_keys.c
*/
void				process_normal_keys(unsigned char key, int x, int y);
/*
** process_special_keys.c
*/
void				process_special_keys(int key, int x, int y);
/*
** read_obj.c
*/
int					read_obj(int ac, char **av);
/*
** render_scene.c
*/
void				render_scene(void);
/*
** set_arrays.c
*/
void				set_vertix_arr(void);
/*
** set_colour.c
*/
int					set_colour(float r, float g, float b);
/*
** store_face.c
*/
void				store_face(char *line, t_list **pos);
/*
** store_obj.c
*/
void				store_struct(void const *struc, size_t size, t_list **pos);
void				store_vertex(char *line, t_list **pos);
void				store_normal(char *line, t_list **pos);
void				store_texture(char *line, t_list **pos);
void				store_pspace(char *line, t_list **pos);
/*
** trim.c
*/
char				*trim_start(char *str);
void				trim_end(char *str);
int					trim_tabs(char *line);
void				trim_str(char *str);
/*
** vertex_create.c
*/
t_vertex			vertex_create(float x, float y, float z, float w);


/*
** snowman.c
*/
void				drawSnowMan();

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif

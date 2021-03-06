/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:00:09 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/11 15:00:11 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define CL_USE_DEPRECATED_OPENCL_1_2_APIS
# define FIRST	-1

# include <CL/cl.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"

typedef struct			s_opcl
{
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	command_queue;
	cl_context			context;
	cl_int				*mem_param;
	cl_mem				memobj_param;
	cl_int				memlenth_param;
	cl_double			*mem_c;
	cl_mem				memobj_c;
	cl_int				memlenth_c;
	cl_int				*mem_tl;
	cl_mem				memobj_tl;
	cl_int				memlenth_tl;
}						t_opcl;

typedef struct			s_point
{
	double				re;
	double				im;
}						t_point;

typedef struct			s_fr
{
	int					width;
	int					height;
	int					bpp;
	int					size;
	int					endian;
	void				*mlx;
	void				*win;
	void				*img;
	char				*line;
	t_point				min;
	t_point				max;
	t_point				f;
	t_point				julia_k;
	t_opcl				opcl;
	int					max_iter;
	int					name;
	int					color;
	int					smooth;
	int					julia_stop;
}						t_fr;

int						key_hooks(int key, void *fr);

int						mouse_hooks(int button, int x, int y, void *fr);
int						mousemove_hook(int x, int y, void *fr_temp);

t_point					create_cmplx(double re, double im);
int						ft_strequ(char *s, char *ss);
void					iferror(char *s);
char					*ft_copy(char *buf, int length);
void					set_new_values(double *a, double *b, double d);

void					put_pixel(t_fr *fr);

void					init_opcl(t_fr *fr);

void					init_arg_1(t_fr *fr);
void					init_arg_2(t_fr *fr);
void					init_arg_3(t_fr *fr);

#endif

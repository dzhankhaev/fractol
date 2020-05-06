#include "fractol.h"

void		init_arg_1(t_fr *fr)
{
	cl_int	ret;
	t_opcl	*opcl;

	opcl = &fr->opcl;
	opcl->memlenth_w_h = 2;
	if (!(opcl->mem_w_h = (cl_int *)malloc(sizeof(cl_int)
										   * opcl->memlenth_w_h)))
		iferror("ERROR init_arguments.c init_arg_1 malloc\n");
	opcl->memobj_w_h = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_w_h * sizeof(cl_int), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_1 clCreateBuffer\n");
	opcl->mem_w_h[0] = fr->width;
	opcl->mem_w_h[1] = fr->height;
	ret = clEnqueueWriteBuffer(opcl->command_queue, opcl->memobj_w_h, CL_TRUE,
							   0, opcl->memlenth_w_h * sizeof(cl_int),
							   opcl->mem_w_h, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_1 clEnqueueWriteBuffer\n");
	ret = clSetKernelArg(opcl->kernel, 0, sizeof(cl_mem),
						 (void *)&opcl->memobj_w_h);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_1 clSetKernelArg\n");
}

static void		set_arg_2(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;

	opcl = &fr->opcl;
	opcl->mem_min_max_f[0] = fr->min.re;
	opcl->mem_min_max_f[1] = fr->min.im;
	opcl->mem_min_max_f[2] = fr->max.re;
	opcl->mem_min_max_f[3] = fr->max.im;
	opcl->mem_min_max_f[4] = fr->f.re;
	opcl->mem_min_max_f[5] = fr->f.im;
	ret = clEnqueueWriteBuffer(opcl->command_queue,
							   opcl->memobj_min_max_f, CL_TRUE, 0,
							   opcl->memlenth_min_max_f * sizeof(cl_double),
							   opcl->mem_min_max_f, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_2 clEnqueueWriteBuffer\n");
	ret = clSetKernelArg(opcl->kernel, 1, sizeof(cl_mem),
						 (void *)&opcl->memobj_min_max_f);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_2 clSetKernelArg\n");
}

void		init_arg_2(t_fr *fr)
{
	t_opcl		*opcl;
	cl_int		ret;

	opcl = &fr->opcl;
	opcl->memlenth_min_max_f = 6;
	if (!(opcl->mem_min_max_f = (cl_double *)malloc(sizeof(cl_double)
			* opcl->memlenth_min_max_f)))
		iferror("ERROR init_arguments.c init_arg_2 malloc\n");

	opcl->memobj_min_max_f = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_min_max_f * sizeof(cl_double), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_2 clCreateBuffer\n");
	set_arg_2(fr);
}

static void		set_arg_3(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;

	opcl = &fr->opcl;
	opcl->mem_max_iter[0] = fr->max_iter;
	ret = clEnqueueWriteBuffer(opcl->command_queue,
							   opcl->memobj_max_iter, CL_TRUE, 0,
							   opcl->memlenth_max_iter * sizeof(cl_int),
							   opcl->mem_max_iter, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_3 clEnqueueWriteBuffer\n");
	ret = clSetKernelArg(opcl->kernel, 2, sizeof(cl_mem),
						 (void *)&opcl->memobj_max_iter);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_3 clSetKernelArg\n");
}

void		init_arg_3(t_fr *fr)
{
	t_opcl		*opcl;
	cl_int		ret;

	opcl = &fr->opcl;
	opcl->memlenth_max_iter = 1;
	if (!(opcl->mem_max_iter = (cl_int *)malloc(sizeof(cl_int)
												* opcl->memlenth_max_iter)))
		iferror("ERROR init_arguments.c init_arg_3 malloc\n");
	opcl->memobj_max_iter = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_max_iter * sizeof(cl_int), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_3 clCreateBuffer\n");
	set_arg_3(fr);
}
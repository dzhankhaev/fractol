#include "fractol.h"

void		set_arg_1(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;

	opcl = &fr->opcl;
	opcl->mem_w_mi[0] = fr->width;
	opcl->mem_w_mi[1] = fr->max_iter;
	opcl->mem_w_mi[2] = fr->name;
	opcl->mem_w_mi[3] = fr->color;
	opcl->mem_w_mi[4] = fr->smooth;
	ret = clEnqueueWriteBuffer(opcl->command_queue, opcl->memobj_w_mi, CL_TRUE,
							   0, opcl->memlenth_w_mi * sizeof(cl_int),
							   opcl->mem_w_mi, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_1 clEnqueueWriteBuffer\n");
}

void		init_arg_1(t_fr *fr)
{
	cl_int	ret;
	t_opcl	*opcl;

	opcl = &fr->opcl;
	opcl->memlenth_w_mi = 5;
	if (!(opcl->mem_w_mi = (cl_int *)malloc(sizeof(cl_int)
										   * opcl->memlenth_w_mi)))
		iferror("ERROR init_arguments.c init_arg_1 malloc\n");
	opcl->memobj_w_mi = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_w_mi * sizeof(cl_int), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_1 clCreateBuffer\n");
	set_arg_1(fr);
	ret = clSetKernelArg(opcl->kernel, 0, sizeof(cl_mem),
						 (void *)&opcl->memobj_w_mi);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_1 clSetKernelArg\n");
}

void		set_arg_2(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;

	opcl = &fr->opcl;
	opcl->mem_c[0] = fr->min.re;
	opcl->mem_c[1] = fr->max.im;
	opcl->mem_c[2] = fr->f.re;
	opcl->mem_c[3] = fr->f.im;
	opcl->mem_c[4] = fr->julia_k.re;
	opcl->mem_c[5] = fr->julia_k.im;
	ret = clEnqueueWriteBuffer(opcl->command_queue,
							   opcl->memobj_c, CL_TRUE, 0,
							   opcl->memlenth_c * sizeof(cl_double),
							   opcl->mem_c, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c set_arg_2 clEnqueueWriteBuffer\n");
}

void		init_arg_2(t_fr *fr)
{
	t_opcl		*opcl;
	cl_int		ret;

	opcl = &fr->opcl;
	opcl->memlenth_c = 6;
	if (!(opcl->mem_c = (cl_double *)malloc(sizeof(cl_double)
			* opcl->memlenth_c)))
		iferror("ERROR init_arguments.c init_arg_2 malloc\n");
	opcl->memobj_c = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_c * sizeof(cl_double), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_2 clCreateBuffer\n");
	set_arg_2(fr);
	ret = clSetKernelArg(opcl->kernel, 1, sizeof(cl_mem),
						 (void *)&opcl->memobj_c);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_2 clSetKernelArg\n");
}

void		init_arg_3(t_fr *fr)
{
	t_opcl		*opcl;
	cl_int		ret;

	opcl = &fr->opcl;
	opcl->memlenth_tl = 3 * fr->height * fr->width;
	if (!(opcl->mem_tl = (cl_int *)malloc(sizeof(cl_int)
			* opcl->memlenth_tl)))
		iferror("ERROR init_arguments.c init_arg_3 malloc\n");
	opcl->memobj_tl = clCreateBuffer(opcl->context, CL_MEM_READ_WRITE,
			opcl->memlenth_tl * sizeof(cl_int), NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_3 clCreateBuffer\n");
	ret = clEnqueueWriteBuffer(opcl->command_queue, opcl->memobj_tl, CL_TRUE,
							   0, opcl->memlenth_tl * sizeof(cl_int),
							   opcl->mem_tl, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_3 clEnqueueWriteBuffer\n");
	ret = clSetKernelArg(opcl->kernel, 2, sizeof(cl_mem),
						 (void *)&opcl->memobj_tl);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_arguments.c init_arg_3 clSetKernelArg\n");
}

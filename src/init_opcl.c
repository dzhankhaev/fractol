#include "fractol.h"

static void		create_kernel(t_opcl *opcl, cl_device_id device_id)
{
	char				buf[2000];
	char				*source_str;
	int					source_length;
	int					fd;
	cl_int				ret;

	if ((fd = open("src/cltest.cl", O_RDONLY)) < 1)
		iferror("ERROR init_opcl.c create_kernel open\n");
	source_length = read(fd, buf, 2000);
	close(fd);
	if (!(source_str = ft_copy(buf, source_length)))
		iferror("ERROR init_opcl.c create_kernel ft_copy\n");
	opcl->program = clCreateProgramWithSource(opcl->context, 1,
			(const char **)&source_str, 0, &ret);
	free(source_str);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_opcl.c create_kernel clCreateProgramWithSource\n");
	if ((ret = clBuildProgram(opcl->program, 1, &device_id, NULL,
							  NULL, NULL)) != CL_SUCCESS)
		iferror("ERROR init_opcl.c create_kernel clBuildProgram\n");
	opcl->kernel = clCreateKernel(opcl->program, "test", &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_opcl.c create_kernel clCreateKernel\n");
}

void			init_opcl(t_fr *fr)
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_int				ret;
	t_opcl				*opcl;

	opcl = &fr->opcl;
	if (clGetPlatformIDs(1, &platform_id, 0) != CL_SUCCESS)
		iferror("ERROR init_opcl.c init_opcl clGetPlatformIDs\n");
	if (clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, 0)
		!= CL_SUCCESS)
		iferror("ERROR init_opcl.c init_opcl clGetDeviceIDs\n");
	opcl->context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_opcl.c init_opcl clCreateContext\n");
	opcl->command_queue = clCreateCommandQueue(opcl->context,
			device_id, 0, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_opcl.c init_opcl clCreateCommandQueue\n");
	create_kernel(opcl, device_id);
	init_arg_1(fr); /*1 - параметры длины и ширины окна. Неизменяемые*/
	init_arg_3(fr); /*2 - максимальное количество итераций. Пока неизменяемый*/
}

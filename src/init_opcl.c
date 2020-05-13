#include "fractol.h"

static void		free_tab(char **tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void		read_cl_files(t_opcl *opcl)
{
	char				buf[3000];
	char				**source_str;
	int					source_length;
	int					fd;
	cl_int				ret;

	if (!(source_str = (char **)malloc(sizeof(char *) * 2)))
		iferror("ERROR init_opcl.c read_cl_files malloc\n");
	if ((fd = open("src/cl_main.cl", O_RDONLY)) < 1)
		iferror("ERROR init_opcl.c read_cl_files open1\n");
	source_length = read(fd, buf, 2000);
	close(fd);
	if (!(source_str[0] = ft_copy(buf, source_length)))
		iferror("ERROR init_opcl.c read_cl_files ft_copy1\n");
	if ((fd = open("src/cl_fractals.cl", O_RDONLY)) < 1)
		iferror("ERROR init_opcl.c read_cl_files open2\n");
	source_length = read(fd, buf, 3000);
	close(fd);
	if (!(source_str[1] = ft_copy(buf, source_length)))
		iferror("ERROR init_opcl.c read_cl_files ft_copy2\n");
	opcl->program = clCreateProgramWithSource(opcl->context, 2,
			(const char **)source_str, 0, &ret);
	if (ret != CL_SUCCESS)
		iferror("ERROR init_opcl.c read_cl_files clCreateProgramWithSource\n");
	free_tab(source_str, 2);
}

static void		create_kernel(t_opcl *opcl, cl_device_id device_id)
{
	cl_int				ret;

	read_cl_files(opcl);
	if ((ret = clBuildProgram(opcl->program, 1, &device_id, NULL,
							  NULL, NULL)) != CL_SUCCESS)
		iferror("ERROR init_opcl.c create_kernel clBuildProgram\n");
	opcl->kernel = clCreateKernel(opcl->program, "calc_pix", &ret);
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
}

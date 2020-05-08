#define WIDTH		w_mi[0]
#define MAX_ITER	w_mi[1]
#define MIN_RE		c[0]
#define MAX_IM		c[1]
#define F_RE		c[2]
#define F_IM		c[3]

void			color(int **line, double t, int k);

__kernel void	test(__global int *w_mi, __global double *c,
		__global int *line)
{
	int		gid;
	int		iter;
	int		x;
	int		y;
	double	cre;
	double	cim;
	double	zre;
	double	zim;
	double	temp;

	gid = get_global_id(0);
	y = gid / WIDTH;
	x = gid % WIDTH;
	cim = MAX_IM - y * F_IM; /* gid / WIDTH = y */
	cre = MIN_RE + x * F_RE; /* gid % WIDTH = x */
	iter = 0;
	zre = cre;
	zim = cim;
	while (zre * zre + zim * zim <= 4 && iter < MAX_ITER)
	{
		temp = zre;
		zre = zre * zre - zim * zim + cre;
		zim = 2.0 * temp * zim + cim;
		iter++;
	}
	color(&line, (double)iter / (double)MAX_ITER, x * 3 + y * 3 * WIDTH);
}

void			color(int **line, double t, int k)
{
	line[0][k + 2] = (int)(9 * (1 - t) * t * t * t * 255);
	line[0][k + 1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	line[0][k] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

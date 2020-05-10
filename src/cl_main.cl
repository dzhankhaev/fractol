#define WIDTH		w_mi[0]
#define MAX_ITER	w_mi[1]
#define	FR_ID		w_mi[2]
#define MIN_RE		c[0]
#define MAX_IM		c[1]
#define F_RE		c[2]
#define F_IM		c[3]

double			fractal(double cre, double cim, int max_iter, int fr_id);

static void		color(int **line, double t, int k)
{
	line[0][k + 2] = (int)(9 * (1 - t) * t * t * t * 255);
	line[0][k + 1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	line[0][k] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

__kernel void	calc_pix(__global int *w_mi, __global double *c,
		__global int *line)
{
	int		gid;
	int		x;
	int		y;
	double	cre;
	double	cim;
	double	t;

	gid = get_global_id(0);
	y = gid / WIDTH;
	x = gid % WIDTH;
	cim = MAX_IM - y * F_IM;
	cre = MIN_RE + x * F_RE;
	t = fractal(cre, cim, MAX_ITER, FR_ID);
	color(&line, t, x * 3 + y * 3 * WIDTH);
}


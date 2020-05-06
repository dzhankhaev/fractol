/*
static void	color(double t, t_fr *fr, int x, int y)
{
	char	*temp;
	int		r;
	int		g;
	int		b;

	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	if (y < fr->height && x < fr->width)
	{
		temp = (char *) (fr->line + (y * 4 * fr->width));
		temp[x * 4] = (char) b;
		temp[x * 4 + 1] = (char) g;
		temp[x * 4 + 2] = (char) r;
	}
}

 */

__kernel void test(__global int *w_h, __global double *min_max_f,
				   __global int *max_iter)
{
	int gid = get_global_id(0);
	min_max_f[gid] += gid + 1;
	max_iter[0] = 33;
}
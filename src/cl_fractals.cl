#define K_RE	args[0]
#define K_IM	args[1]
#define C_IM	args[2]
#define C_RE	args[3]

static double	mandelbrot(double cre, double cim, int max_iter, int smooth)
{
	double	temp;
	int		iter;
	double	zre;
	double	zim;

	iter = 0;
	zre = cre;
	zim = cim;
	while (zre * zre + zim * zim <= 4 && iter < max_iter)
	{
		temp = zre;
		zre = zre * zre - zim * zim + cre;
		zim = 2.0 * temp * zim + cim;
		iter++;
	}
	if (iter == max_iter || iter == 0)
		return (0);
	if (smooth == 1)
		return (((double)iter - log2(log2(zre * zre + zim * zim)) + 1.5)
		/ (double)max_iter);
	return ((double)iter / (double)max_iter);
}

static double	burning_ship(double cre, double cim, int max_iter, int smooth)
{
	double	temp;
	int		iter;
	double	zre;
	double	zim;

	iter = 0;
	zre = cre;
	zim = cim;
	while (zre * zre + zim * zim <= 4 && iter < max_iter)
	{
		temp = zre;
		zre = zre * zre - zim * zim + cre;
		temp *= zim;
		if (temp < -0.0)
			temp *= -1;
		zim = -2.0 * temp + cim;
		iter++;
	}
	if (iter == max_iter || iter == 0)
		return (0);
	if (smooth == 1)
		return (((double)iter - log2(log2(zre * zre + zim * zim)) + 1.5)
				/ (double)max_iter);
	return ((double)iter / (double)max_iter);
}

static double	celtic_mandelbrot(double cre, double cim, int max_iter,
		int smooth)
{
	double	temp;
	int		iter;
	double	zre;
	double	zim;

	iter = 0;
	zre = cre;
	zim = cim;
	while (zre * zre + zim * zim <= 4 && iter < max_iter)
	{
		temp = zre * zre - zim * zim;
		if (temp < -0.0)
			temp *= -1;
		zim = 2.0 * zre * zim + cim;
		zre = temp + cre;
		iter++;
	}
	if (iter == max_iter || iter == 0)
		return (0);
	if (smooth == 1)
		return (((double)iter - log2(log2(zre * zre + zim * zim)) + 1.5)
				/ (double)max_iter);
	return ((double)iter / (double)max_iter);
}

static double	julia(double *args, int max_iter, int smooth)
{
	double	temp;
	int		iter;
	double	zre;
	double	zim;

	iter = 0;
	zre = C_RE;
	zim = C_IM;
	while (zre * zre + zim * zim <= 4 && iter < max_iter)
	{
		temp = zre;
		zre = zre * zre - zim * zim + K_RE;
		zim = 2.0 * temp * zim + K_RE;
		iter++;
	}
	if (iter == max_iter || iter == 0)
		return (0);
	if (smooth == 1)
		return (((double)iter - log2(log2(zre * zre + zim * zim)) + 1.5)
				/ (double)max_iter);
	return ((double)iter / (double)max_iter);
}

double			iter_count(double *args, int max_iter, int fr_id, int smooth)
{
	if (fr_id == 0)
		return (mandelbrot(C_RE, C_IM, max_iter, smooth));
	else if (fr_id == 1)
		return (burning_ship(C_RE, C_IM, max_iter, smooth));
	else if (fr_id == 2)
		return (celtic_mandelbrot(C_RE, C_IM, max_iter, smooth));
	else if (fr_id == 3)
		return (julia(args, max_iter, smooth));
}

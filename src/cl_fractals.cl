
static double	mandelbrot(double cre, double cim, int max_iter)
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
	return ((double)iter / (double)max_iter);
}

static double	burning_ship(double cre, double cim, int max_iter)
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
	return ((double)iter / (double)max_iter);
}

static double	celtic_mandelbrot(double cre, double cim, int max_iter)
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
	return ((double)iter / (double)max_iter);
}

double			fractal(double cre, double cim, int max_iter, int fr_id)
{
	if (fr_id == 0)
		return (mandelbrot(cre, cim, max_iter));
	else if (fr_id == 1)
		return (burning_ship(cre, cim, max_iter));
	else if (fr_id == 2)
		return (celtic_mandelbrot(cre, cim, max_iter));
}
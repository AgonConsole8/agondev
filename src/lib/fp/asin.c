/************************************************************************/
/*									*/
/*			Copyright (C) 2000-2008 Zilog, Inc.		*/
/*									*/
/************************************************************************/
/*
	asin(arg) and acos(arg) return the arcsin, arccos,
	respectively of their arguments.

	Arctan is called after appropriate range reduction.
*/

#include	<errno.h>
#include	<math.h>

#define pio2  1.57079632679490

double asin(double arg)
{

	double sign, temp;

	sign = 1.;
	if(arg <0){
		arg = -arg;
		sign = -1.;
	}

	if(arg > 1.){
		errno = EDOM;
		return(0.);
	}

	temp = sqrt(1. - arg*arg);
	if(arg > 0.7)
		temp = pio2 - atan(temp/arg);
	else
		temp = atan(arg/temp);

	return(sign*temp);
}

float asinf(float) __attribute__((alias("asin")));

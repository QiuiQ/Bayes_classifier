// Bayes.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <math.h>

double caculatePropability(double data[][4], int dataHeight, int dataWidth, double* test)
{
	int totalDisL=0, totalLike=0, countD=0, countL=0;
	double *likePHE = new double[dataWidth - 1], *disPHE = new double[dataWidth - 1], sumD = 0.5, sumL = 0.5, sumDL=0, p;
	for (int i = 0; i < dataWidth - 1; i++) { likePHE[i] = 0; disPHE[i] = 0; }

	for (int i = 0; i < dataHeight; i++)
	if (data[i][dataWidth - 1] == 0) totalDisL++;
	else totalLike++;

	for (int i = 0; i < dataWidth-1; i++)
	{
		for (int j = 0; j < dataHeight; j++)
		if (data[j][i] == test[i] && data[j][dataWidth - 1] == 1) likePHE[i]++;
		else if (data[j][i] == test[i] && data[j][dataWidth - 1] == 0) disPHE[i]++;
	}
	
	for (int i = 0; i < dataWidth - 1; i++)
	{
		sumD *= (disPHE[i] / totalDisL);
		sumL *= (likePHE[i] / totalLike);
	}
	sumDL = sumD + sumL;
	p = sumL / sumDL;
	return p;
}
double caculateSTD(double p, int n)
{ 
	return sqrt((p * (1 - p)) / n); 
}
int _tmain(int argc, _TCHAR* argv[])
{
	int height = 21, width = 4;
	/*double **data;
	data = new double*[height];
	for (int i = 0; i < height; i++) data[i] = new double[width];*/
	double data[21][4] = {
		1, 0, 1, 1,
		0, 0, 0, 1,
		0, 1, 1, 0,
		1, 0, 0, 0,
		1, 1, 1, 0,
		0, 0, 0, 0,
		0, 0, 0, 1,
		0, 0, 1, 0,
		0, 0, 1, 1,
		0, 1, 0, 0,
		0, 1, 0, 1,
		0, 1, 1, 0,
		0, 1, 1, 1,
		1, 0, 0, 0,
		1, 0, 0, 1,
		1, 0, 1, 0,
		1, 0, 1, 1,
		1, 1, 0, 0,
		1, 1, 0, 1,
		1, 1, 1, 0,
		1, 1, 1, 1 };
	double test[3] = {1,1,1};

	double p = caculatePropability(data, height, width, test);
	double std = caculateSTD(p, height);
	printf("%lf\n%lf\n", p, std);
	return 0;
}


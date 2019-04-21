//#include "StdAfx.h"
#include "smath.h"

Vector::Vector(void)
{
     count = 0;
     pM = NULL;
	 flag_destr = false;
}

Vector::~Vector(void)
{
	if (pM != NULL)delete[] pM;
	pM =NULL;
}

int Vector::init(int x_count)
{
	pM = new int [x_count];
	if (pM == NULL) return 1;
	count = x_count;
    flag_destr = true;
	return 0;
}

int Vector::null(void)
{
	if (pM == NULL || count == 0) return 1;
	for (register i =0; i<count ;i++) pM[i] = 0;
	return 0;
}

int Vector::initM(int* pxM)
{
	if (pM == NULL || pxM == NULL || count == 0)return 1;
	for(register i = 0; i<count; i++) pM[i] = pxM[i];
	return 0;
}

int Vector::init(int x_count, int* pxM)
{
	if(init(x_count) == 0 && initM(pxM) == 0) return 0;
	return 1;
}

int Vector::sort(void)
{
	register i,j,temp;
	for(i = 0; i<count ; i++)
		for(j = count; j>i; j--)
		{
			if(pM[j-1]<pM[j])
			{
				temp = pM[j];
				pM[j]=pM[j-1];
				pM[j-1] = temp;
			}
		}

	return 0;
}


Matrix::Matrix(void)
: countX(0)
, countY(0)
, pMat(NULL)
, ptemp(NULL)
{
}

Matrix::~Matrix(void)
{
	if( pMat != NULL) delete[] pMat;
	pMat = NULL;
	if (ptemp != NULL) delete[] ptemp;
	ptemp = 0;
}

int Matrix::init(int x_count, int y_count)
{
	pMat = new int[x_count*y_count];
	if (pMat == NULL) return 1;
    countX = x_count;
	countY = y_count;
	ptemp = new int[countY];
	//Vx.init(countY);
	//Vy.init(countX);
	return 0;
}

int Matrix::null(void)
{
	if ( pMat == NULL || countX == 0 || countY == 0) return 1;
	int P = countX*countY;
	for(register i = 0 ;i < P;i ++)pMat[i] = 0;
	return 0;
}

int Matrix::initM(int* pM)
{
	if ( pMat == NULL || countX == 0 || countY == 0) return 1;
	int P = countX*countY;
	for( register i = 0; i < P; i++) pMat[i] = pM[i];
	return 0;
}

int Matrix::init(int x_count, int y_count, int* pM)
{
	if(init(x_count,y_count) == 0 && initM(pM) == 0) return 0;
	return 1;
}

int* Matrix::getx(int index)
{
	int Index = index;
	for(register i = 0; i < countY; i++)
	{
		ptemp[i] = *(pMat+Index+i*countX);
	}
	return ptemp;
}



int Matrix::sort(int index)
{
	register i,j,k,temp;
	for(i = 0; i<countX-1 ; i++)
		for(j = countX-1; j>i; j--)
		{
			if((*this)[index][j]>(*this)[index][j-1])
			{
				for(k = 0; k < countY; k++)
				{
					temp = (*this)[k][j];
					(*this)[k][j]=(*this)[k][j-1];
					(*this)[k][j-1] = temp;
				}
			}
		}
	return 0;
}

int Matrix::sortY(int index)
{
	register i,j,k,temp;
	for(i = 0; i<countY-1 ; i++)
		for(j = countY-1; j>i; j--)
		{
			if((*this)[j][index]>(*this)[j-1][index])
			{
				for(k = 0; k < countX; k++)
				{
					temp = (*this)[j][k];
					(*this)[j][k]=(*this)[j-1][k];
					(*this)[j-1][k] = temp;
				}
			}
		}
	return 0;
}

int Matrix::addVectorX(int index, Vector* v1)
{
	if(pMat == 0 || v1->pM == NULL || countX != v1->count) return 1;
	for(register i = 0 ; i < countX; i ++) (*this)[index][i] = (*v1)[i];
	return 0;
}

int Matrix::addVectorY(int index, Vector* v1)
{
	if(pMat == 0 || v1->pM == NULL || countY != v1->count) return 1;
	for(register i = 0 ; i < countY; i ++) (*this)[i][index] = (*v1)[i];
	return 0;
}

#pragma once

#define NULL 0
class Vector
{
public:
    // конструктор
	Vector(void);
    // деструктор
	~Vector(void);
	// количество элементов
	int count;
	// указатель на массив
	int* pM;
    // функция инициализации
	int init(int x_count);
    //
	int null(void);
    //
	int initM(int* pxM);
    //
	int init(int x_count, int* pxM);
    // перегрузка оператора []
	int& operator [](int index)
	{
		if(pM == NULL || index >= count)return *pM;
		return pM[index];
	};
    // перегрузка оператора =
	int operator =(Vector &pv)
	{
		if(pM == NULL) init(pv.count,pv.pM);
		else if (count == pv.count)initM(pv.pM);
		return 0;
	};
    // перегрузка оператора =
	int operator =(int *pxM)
	{
		if(pM == NULL && count !=0) init(count,pxM);
		else if(count != 0) initM(pxM);
		return 0;
	};
    // перегрузка оператора -=
	int operator -=(Vector &v)
	{
		for(int i = 0; i<count; i++)
                        pM[i] -= v[i];
		return 0;
	};

    // функция сортировки
	int sort(void);
	bool flag_destr;
};

class Matrix
{
public:
	Matrix(void);
	~Matrix(void);
	int countX;
	int countY;
	int* pMat;
	Vector Vx;
	Vector Vy;
	int init(int x_count, int y_count);
	int null(void);
	int initM(int* pM);
	int init(int x_count, int y_count, int* pM);
	int* operator [] (int index)
	{
		int *pOtn = NULL;
		if(pMat == NULL || index>=countY) return NULL;
		pOtn = pMat+index*countX;
		return pOtn;
	}
	int operator =(Matrix &m)
	{
		if(pMat == NULL) init(m.countX,m.countY,m.pMat);
		else if (countX == m.countX && countY == m.countY)initM(m.pMat);
		return 0;
	}
	int operator =(int *pxM)
	{
		if(pMat == NULL && countX !=0 && countY != 0) init(countX,countY,pxM);
		else if(countX != 0 && countY != 0) initM(pxM);
		return 0;
	}
	int* ptemp;
	int* getx(int index);
	int sort(int index);
	int sortY(int index);
	int addVectorX(int index, Vector* v1);
	int addVectorY(int index, Vector* v1);
};

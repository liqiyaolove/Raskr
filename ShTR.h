#pragma once
#include "smath.cpp"
//#include "stdafx.h"
enum FLPR{BEGIN,STOP};
/* Руководство к использованию.
	ПРИМЕР:
	int im1[] = {.,.,...,.}; //count
	int im2[] = {.,.,...,.}; //count
	int count = ...;
    int Lzag = ...;
	Vector vL,vN;
	Matrix mR;
	ShTR ob;
	
	vL.init(count);
	vN.init(count);
	vL = im1;
	vN = im2;
	
	ob.Init(&vL,&vN,Lzag);
	ob.run();
	ob.get_matrix_raskroy(&mR)
	
	int table_x,table_y;
	table_x = mR.countX;
	table_y = mR.countY;

	int L_i;
	L_i = mR[...][...];
*/
class ShTR
{

public:
	/*ShTR(void);   */
        //int flat;
        ShTR(void);
	~ShTR(void);
	int run(void);
	void test(void);
	int Init(Vector* p_vector_of_L, Vector* p_vector_of_count_L, int L_zagotovki);
//protected:
	FLPR f1;
	int size_table_x;
	int size_table_y;
	int L_raskr_zagotovki;
	int rest_optim_Lraskr_i;
	Vector vector_L;
	Vector vector_count_L;
	Vector teck_count_Lraskr_i;
	Vector optim_count_Lraskr_i;
	Matrix matrix_count_Li;
	Vector vector_rest;
	int Lo_pogon;
	int get_rest(int begin, int Rest);
	int get_matrix_raskroy(Matrix* null_matrix);
	int size_x_min;
};

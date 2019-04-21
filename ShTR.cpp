#include "shtr.h"


 /*ShTR::ShTR(void)
{
   size_table_x = 0;
  size_table_y = 0;
  L_raskr_zagotovki = 0;
  rest_optim_Lraskr_i =0;
  Lo_pogon = 0;
  size_x_min = 0;
}   */
ShTR::ShTR(void) //инициализация матрицы
{
  //flat = 5;
  size_table_x = 0;
  size_table_y = 0;
  L_raskr_zagotovki = 0;
  rest_optim_Lraskr_i =0;
  Lo_pogon = 0;
  size_x_min = 0;
}

ShTR::~ShTR(void) 
{
}

int ShTR::run(void)
{
	int index_of_x = 0; 
	int index_of_y = 0;
	teck_count_Lraskr_i = vector_count_L;
	Vector v_temp;
	v_temp = vector_count_L;
	while(1)
	{
		if( index_of_x>=size_table_x)
		{
			size_x_min = index_of_x;
			break;
		}
		while (	index_of_y <= size_table_y && teck_count_Lraskr_i[index_of_y++] == 0);
		if(index_of_y == size_table_y+1)
		{
			size_x_min = index_of_x;
			break;
		}
		index_of_y--;
		teck_count_Lraskr_i[index_of_y]--;
		
		rest_optim_Lraskr_i = L_raskr_zagotovki - vector_L[index_of_y];
		get_rest(index_of_y,rest_optim_Lraskr_i++);
                rest_optim_Lraskr_i--;
		
		optim_count_Lraskr_i[index_of_y]++;
		v_temp -= optim_count_Lraskr_i;
		teck_count_Lraskr_i = v_temp;
		//teck_count_Lraskr_i -= optim_count_Lraskr_i; 
        
		matrix_count_Li.addVectorY(index_of_x,&optim_count_Lraskr_i);
		index_of_x ++;
                //index_of_y = 0;
		//if(index_of_x == 3)break;
	}
	return 0;
}

void ShTR::test(void)
{
	//while(f1 == BEGIN)	count++;
		
}

int ShTR::Init(Vector* p_vector_of_L, Vector* p_vector_of_count_L, int L_zagotovki) //загрузка и подготовка данных
{
	if (p_vector_of_L->count != p_vector_of_count_L->count ||
		L_zagotovki == 0)
		return 1; 
	
	vector_L		= *p_vector_of_L; //длина заготовки
	vector_count_L	= *p_vector_of_count_L; //кол-во заготовок
		L_raskr_zagotovki = L_zagotovki; // 
	size_table_y = p_vector_of_L->count; //размер таблицы по у
	
	Matrix matrix_sort;   //создаем матрицу для сортировки
	matrix_sort.init(2,size_table_y); //
	matrix_sort.addVectorY(0,&vector_L);
	matrix_sort.addVectorY(1,&vector_count_L);
	matrix_sort.sortY(0);
	vector_L = matrix_sort.getx(0);
	vector_count_L = matrix_sort.getx(1);

        int sum1=0;
	register i;
    for(i = 0; i < size_table_y; i ++)
    {
         Lo_pogon += vector_L[i] * vector_count_L[i];
         sum1+= vector_count_L[i] ;

    }

	//size_table_x = Lo_pogon/L_raskr_zagotovki + 5;
        size_table_x = sum1;
	matrix_count_Li.init(size_table_x,size_table_y);
	matrix_count_Li.null();
    return 0;
}

int ShTR::get_rest(int begin, int Rest)
{
	if(begin == size_table_y)
	{
		if(Rest < rest_optim_Lraskr_i)
		{
			optim_count_Lraskr_i = teck_count_Lraskr_i;
			rest_optim_Lraskr_i = Rest;
		}

		return Rest;
	}
	int max_count;
	register i;
	max_count = (Rest/vector_L[begin] < teck_count_Lraskr_i[begin])?  Rest/vector_L[begin] : teck_count_Lraskr_i[begin];
	int temp_count = teck_count_Lraskr_i[begin];
	//teck_count_Lraskr_i[begin] = max_count;
	for(i = max_count; i>=0; i--)
	{
		teck_count_Lraskr_i[begin] = i;
		get_rest(begin+1,Rest-i*vector_L[begin]);
	}
	teck_count_Lraskr_i[begin] = temp_count;
	return Rest;
}

int ShTR::get_matrix_raskroy(Matrix* null_matrix)
{
	Matrix m_rasz;
	int count_max_y = 0,count_y,temp_count;
	register i,j,k;	
	for(i = 0; i<size_x_min; i++)
	{
		count_y = 0;
		for( j = 0; j < size_table_y; j++)
			count_y += matrix_count_Li[j][i];
		if(count_max_y<count_y)count_max_y = count_y;
	}
	
	m_rasz.init(size_x_min,count_max_y);
	m_rasz.null();
	
	for( i = 0; i<size_x_min; i++)
	{
		k=0;
		for(j=0;j<size_table_y;j++)
		{
			temp_count = matrix_count_Li[j][i];
			while(temp_count > 0)
			{
				m_rasz[k][i] = vector_L[j];
				k++;
				temp_count--;
			}
		}
	}
	*(null_matrix) = m_rasz;
	int Sum = 0;
	for( i =0; i < null_matrix->countX; i ++)
		for (j = 0; j < null_matrix->countY;j++)Sum+=(*null_matrix)[j][i];
	if (Sum != Lo_pogon) return 1;
	return 0;
}

/*
  ���� ������������ ����� 2-3 - ������� ������� ���������� ������ ����������
  ������������ ������ � �������������� �������� � ����������� �������, ���������
  ���� �/C++ � ���������� ������������ ���������� OPENMP.
     ����������: ������������� �.�.�����������
*/
#include "HDeclarations.h"
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <windows.h> // ��� ������������
#define N 3
//int const N=3;

int main()
{
    //������������ ��������� ������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double t0, time, time_sequential;
    int** a = (int**)malloc(N* sizeof(int*));// = new int*[N];
    int** b = (int**)malloc(N* sizeof(int*));
    int** x = (int**)malloc(N* sizeof(int*));
    if (a && b && x != NULL)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = (int*)malloc(N * sizeof(int));
            b[i] = (int*)malloc(N * sizeof(int));
            x[i] = (int*)malloc(N * sizeof(int));
            if (a[i] && b[i] && x[i] != NULL)
            {
                for (int j = 0; j < N; j++)
                {
                    a[i][j] = i * j;
                    b[i][j] = i * j;
                    x[i][j] = 0;
                }
            }
            else
            {
            return E_POINTER;
            }
        }
    } 
    else
    {
        return E_POINTER;
    }

 //         free(a[i]);
 //         free(b[i]);
 //         free(x[i]);
 //       }
      // a[i] = new int[N];
    
    printf("������� ���������� �����������������, �������������, ��������� ������\n");
    t0 = omp_get_wtime();
    matrixProduct(a, b, x, N);
    time_sequential = omp_get_wtime() - t0;
    printf("Calculation time sequential = %f seconds\n", time_sequential);
    //*****************************

    printf("\n������� ���������� ��������� ������ � �������������� ��������� ����������������� \
       single �����������:\n");
    t0 = omp_get_wtime();
    matrixProductSingle(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation using %d threads for directive single= %f seconds, \
       acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);

    // ������� �1
    //printf("\n ������� �1 *******************************************\n");
    //printf("����������� ����� ��������� ������ � �������������� \
	   //���������������� ����������������� � ����������� ����������� �� 2 ������� \
    //   � ��������� ��������� \n");
    //t0 = omp_get_wtime();
    //matrixProductParallel(a, b, x, N);
    //time = omp_get_wtime() - t0;
    //printf("Time of Parallel calculation using 2 column tasks = %f seconds, acceleration S=%f\n",time, time_sequential/time );
    ////*************************
    //// ������� �2
    //printf("\n ������� �2 *******************************************\n");
    //printf("����������� ����� ��������� ������ � �������������� \
	   //���������������� ����������������� �� ������� � ��������� ���������\n");
    //t0 = omp_get_wtime();
    //matrixProductLine(a, b, x, N);
    //time = omp_get_wtime() - t0;
    //printf("Time of Parallel calculation by rows%f seconds, acceleration S=%f\n",time, time_sequential/time );
    // 
    // ������� �3
    /*printf("\n ������� �3  *******************************************\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� ��������� \
       ���������� 2� ������ � ������ � static � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct3ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
   
//    // ������� �4
    /*printf("\n ������� �4  *******************************************\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� ��������� \
       ���������� 2� ������ � ������ � dynamic � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct4ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // ������� �5
    /*printf("\n ������� �5  *******************************************\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� ��������� \
       ���������� 2� ������ � ������ � guided � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct5ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // ������� �6
    /*printf("\n ������� �6  *******************************************\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� ��������� \
       ���������� 2� ������ � ������ � auto � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct6ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // ������� �7
    /*printf("\n ������� �7  *******************************************\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� ��������� \
       ���������� 2� ������ � ������ � runtime � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct7ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
    // ������� �8
    /*printf("\n ������� �8 A B C D E ��� � �������� 3 4 5 6 7 ��������������, �� ��������� ����� collapse*****\n");
    printf("����������� ����� ��������� ������ � �������������� \
	   ���������������� ����������������� ����������� \
       ��������� collapse � ��������� ���������:\n");
    t0 = omp_get_wtime();
    matrixProduct8ex(a, b, x, N);
    time = omp_get_wtime() - t0; 
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
//    // ������� �9
    //printf("\n ������� �9 *******************************************\n");
    //printf("����������� ����� ��������! ����������� ��������� ������ � �������������� \
		  // ��������� ������������� ����������������� if � ������� ���������� omp.h \
    //      � ��������� ��������� :\n");
    //t0=omp_get_wtime();
    // matrixProductIf(a,b,x,N);
    //time=omp_get_wtime()-t0;
    //printf("Time of Parallel calculation %d threads is %f seconds, acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);
//    //**************************
    // ������� �10
    printf("\n ������� �10*******************************************\n");
    printf("����������� ����� ��������! ����������� ��������� ������ � �������������� \
		   ��������� ������������� ����������������� sections � ��������� ���������:\n");
    t0=omp_get_wtime();
      matrixProductSections(a,b,x,N);
    time=omp_get_wtime()-t0;
    printf("Time of Parallel calculation in Sections %d threads is %f seconds, \
            acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);
    printf("\n*********************************************************\n");
//    printf(" \
// ����� ������� � ���������� � ���������� ������������ �����: \n \
//�) �������� ��� ��� �������, � �������� ������ ������� ������ �� ������� \n \
//����������� ��� ������� � ���������� single ����, � �������� ��� �� �������� \n \
//������� 3�3. ����������� �������� �������� ����������. ��� ����� �������� ��� ������� \n \
//cmd.exe ����� ��������� ����c��� ���� ������� (������ ������� ����). \n \
//�) ���������������� � ����� ����������� ������� ProductFunctions.cpp \
//��� �������� ������ �� �������. \n \
//�) ���������� ������ ������ ��� N=1000. �������� � ��������� ���������. \
//��� ������� ����� ����������������� ������� ���������� ������, ����� ���������� ������� \
//� ���������. � ������, ������, � ������ ������ ���� ��������, ������ �, \
//������� ���������� ��� ������ ������� 1000�1000, ����� ���������� �������, \
//���������, ��� ������� ������� 1-4, 8-9 � ��� �� \n \
//�) ������� ����������� ���������� �� ���� ������. \n \
//����������� ������� �� ������� ���������� ������� � �������� - �� ���������� ��������� \n \
//�) ����������� ���������� ���������� ��� ��������� �� � ������������ ������������ ������ \
//�� ������� �������� ����� - TaskBag \
//     ");

    free(a);
    free(b);
    free(x);
  
    return 0;
}

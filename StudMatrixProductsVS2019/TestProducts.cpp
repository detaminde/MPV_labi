/*
  Цель лабораторных работ 2-3 - сравние методов вычисления задачи нахождения
  произведения матриц в вычислительных системах с разделяемой памятью, используя
  язык С/C++ и библиотеку параллельных вычислений OPENMP.
     Подготовил: преподаватель А.Н.Васильченко
*/
#include "HDeclarations.h"
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <windows.h> // для кириллизации
#define N 3
//int const N=3;

int main()
{
    //Кириллизация командной строки
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
    
    printf("Образец выполнения последовательного, однопоточного, умножения матриц\n");
    t0 = omp_get_wtime();
    matrixProduct(a, b, x, N);
    time_sequential = omp_get_wtime() - t0;
    printf("Calculation time sequential = %f seconds\n", time_sequential);
    //*****************************

    printf("\nОбразец выполнения умножения матриц с использованием директивы распараллеливания \
       single поэлементно:\n");
    t0 = omp_get_wtime();
    matrixProductSingle(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation using %d threads for directive single= %f seconds, \
       acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);

    // Задание №1
    //printf("\n Задание №1 *******************************************\n");
    //printf("Представить здесь умножение матриц с использованием \
	   //высокоуровневого распараллеливания с подзадачами содержащими по 2 столбца \
    //   и вычислить ускорение \n");
    //t0 = omp_get_wtime();
    //matrixProductParallel(a, b, x, N);
    //time = omp_get_wtime() - t0;
    //printf("Time of Parallel calculation using 2 column tasks = %f seconds, acceleration S=%f\n",time, time_sequential/time );
    ////*************************
    //// Задание №2
    //printf("\n Задание №2 *******************************************\n");
    //printf("Представить здесь умножение матриц с использованием \
	   //высокоуровневого распараллеливания по строкам и вычислить ускорение\n");
    //t0 = omp_get_wtime();
    //matrixProductLine(a, b, x, N);
    //time = omp_get_wtime() - t0;
    //printf("Time of Parallel calculation by rows%f seconds, acceleration S=%f\n",time, time_sequential/time );
    // 
    // Задание №3
    /*printf("\n Задание №3  *******************************************\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно используя \
       приведение 2х циклов к одному и static и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct3ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
   
//    // Задание №4
    /*printf("\n Задание №4  *******************************************\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно используя \
       приведение 2х циклов к одному и dynamic и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct4ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // Задание №5
    /*printf("\n Задание №5  *******************************************\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно используя \
       приведение 2х циклов к одному и guided и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct5ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // Задание №6
    /*printf("\n Задание №6  *******************************************\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно используя \
       приведение 2х циклов к одному и auto и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct6ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
//    //****************************
    // Задание №7
    /*printf("\n Задание №7  *******************************************\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно используя \
       приведение 2х циклов к одному и runtime и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct7ex(a, b, x, N);
    time = omp_get_wtime() - t0;
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
    // Задание №8
    /*printf("\n Задание №8 A B C D E как в заданиях 3 4 5 6 7 соответственно, но используя опцию collapse*****\n");
    printf("Представить здесь умножение матриц с использованием \
	   высокоуровневого распараллеливания поэлементно \
       используя collapse и вычислить ускорение:\n");
    t0 = omp_get_wtime();
    matrixProduct8ex(a, b, x, N);
    time = omp_get_wtime() - t0; 
    printf("Time of Parallel calculation where an element is a task= %f seconds, acceleration S=%f\n",time, time_sequential/time );*/
    //****************************
//    // Задание №9
    //printf("\n Задание №9 *******************************************\n");
    //printf("Представить здесь наиболее! эффективное умножение матриц с использованием \
		  // директивы низкоуровнего распараллеливания if и функций библиотеки omp.h \
    //      и вычислить ускорение :\n");
    //t0=omp_get_wtime();
    // matrixProductIf(a,b,x,N);
    //time=omp_get_wtime()-t0;
    //printf("Time of Parallel calculation %d threads is %f seconds, acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);
//    //**************************
    // Задание №10
    printf("\n Задание №10*******************************************\n");
    printf("Представить здесь наиболее! эффективное умножение матриц с использованием \
		   директивы низкоуровнего распараллеливания sections и вычислить ускорение:\n");
    t0=omp_get_wtime();
      matrixProductSections(a,b,x,N);
    time=omp_get_wtime()-t0;
    printf("Time of Parallel calculation in Sections %d threads is %f seconds, \
            acceleration S=%f\n", omp_get_num_procs(), time, time_sequential / time);
    printf("\n*********************************************************\n");
//    printf(" \
// Общее задание и требования к выполнению Лабораторных Работ: \n \
//А) Написать код для заданий, в точности следуя образцу вывода на монитор \n \
//приведённому для задания с директивой single выше, и отладить его на матрицах \n \
//размера 3Х3. Обязательно сделайте скриншот вычислений. Для этого сделайте фон консоли \n \
//cmd.exe белым используя свойcтва окна консоли (правой кнопкой мыши). \n \
//Б) Закомментировать в файле определений функций ProductFunctions.cpp \
//все операции вывода на монитор. \n \
//В) Установить размер матриц для N=1000. Отладить и запустить программу. \
//Для выводов нужны продолжительность времени выполнения задачи, общее количество потоков \
//и ускорение. В отчёте, выводе, к работе должны быть скриншот, пункта А, \
//времена вычислений для матриц размера 1000Х1000, общее количество потоков, \
//ускорение, код решения заданий 1-4, 8-9 а так же \n \
//Г) Сравние результатов вычислений по этой работе. \n \
//Расположите задания по порядку увеличения времени и отдельно - по уменьшению ускорений \n \
//Д) Используйте результаты вычислений для сравнения их с результатами лабораторной работы \
//по проекту портфель задач - TaskBag \
//     ");

    free(a);
    free(b);
    free(x);
  
    return 0;
}

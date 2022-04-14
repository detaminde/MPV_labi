#include<stdio.h>
#include<omp.h>

// Sequentil, not parallel, calculation of matrix x T = time_sequential
void matrixProduct(int** a, int** b, int** x, int const S)
{
    int sum = 0;    int i, j, k;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S; j++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i][k] * b[k][j];
            x[i][j] = sum;
            printf("Matrix product x[%d, %d] = %d for thread=%d \n", i, j, x[i][j], omp_get_thread_num());
        }
    }
}
//---- A sample of parallel calculation with single directive ------
void matrixProductSingle(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, j, k, coun = 0;
#pragma omp parallel num_threads(6) shared(a,b,x) \
        private(i,j,k) firstprivate(sum,coun) //private(coun)
    {
        for (i = 0; i < S; i++)
        {
            for (j = 0; j < S; j++)
            {
#pragma omp single nowait
                {
                    sum = 0;
                    for (k = 0; k < S; k++)sum += a[i][k] * b[k][j];
                    x[i][j] = sum;
                    printf("Matrix product x[%d, %d] = %d single in thread=%d\n", i, j, x[i][j], omp_get_thread_num());
                    coun++;
                }
            }
        }
        printf("Thread# %d calculated %d matrix elements\n", omp_get_thread_num(), coun);
    }//end of parallel scope
}

void matrixProductParallel(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, j, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i,j,k) 
    {

#pragma omp for schedule(static, 2) 
        for (i = 0; i < S; i++)
        {
            for (j = 0; j < S; j++)
            {
                sum = 0;
                for (k = 0; k < S; k++)sum += a[i][k] * b[k][j];
                x[i][j] = sum;
                //printf("Matrix product x[%d, %d] = %d for thread=%d \n", i, j, x[i][j], omp_get_thread_num());
            }
        }
    }
}

void matrixProductLine(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, j, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i,j,k) 
    {

#pragma omp for 
        for (i = 0; i < S; i++)
        {
            for (j = 0; j < S; j++)
            {
                sum = 0;
                for (k = 0; k < S; k++)sum += a[i][k] * b[k][j];
                x[i][j] = sum;
                printf("Matrix product x[%d, %d] = %d for thread=%d \n", i, j, x[i][j], omp_get_thread_num());
            }
        }
    }
}

void matrixProduct3ex(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i, k) 
    {
#pragma omp for schedule(static, 2)
        for (i = 0; i < S * S; i++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i/S][k] * b[k][i%S];
            x[i / S][i % S] = sum; 
            printf("Matrix product x[%d, %d] = %d for thread=%d \n", 
                i/S, i%S, x[i/S][i%S], omp_get_thread_num());
        }        
    }
}

void matrixProduct4ex(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i, k) 
    {
#pragma omp for schedule(dynamic, 2)
        for (i = 0; i < S * S; i++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i / S][k] * b[k][i % S];
            x[i / S][i % S] = sum;
            printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                i / S, i % S, x[i / S][i % S], omp_get_thread_num());
        }

    }
}

void matrixProduct5ex(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i, k) 
    {
#pragma omp for schedule(guided, 2)
        for (i = 0; i < S * S; i++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i / S][k] * b[k][i % S];
            x[i / S][i % S] = sum;
            printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                i / S, i % S, x[i / S][i % S], omp_get_thread_num());
        }

    }
}

void matrixProduct6ex(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i, k) 
    {
#pragma omp for schedule(guided, 2)
        for (i = 0; i < S * S; i++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i / S][k] * b[k][i % S];
            x[i / S][i % S] = sum;
            printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                i / S, i % S, x[i / S][i % S], omp_get_thread_num());
        }

    }
}

void matrixProduct7ex(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i, k) 
    {
    
#pragma omp for schedule(guided, 2)
        for (i = 0; i < S * S; i++)
        {
            sum = 0;
            for (k = 0; k < S; k++)sum += a[i / S][k] * b[k][i % S];
            x[i / S][i % S] = sum;
            printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                i / S, i % S, x[i / S][i % S], omp_get_thread_num());
        }

    }
}

void matrixProductIf(int** a, int** b, int** x, int const S)
{
    int sum = 0; int i, k, j, count = 0;
#pragma omp parallel shared(a,b,x) \
             firstprivate(sum, count) \
             private(i,j,k) 
#pragma omp for
    for (i = 0; i < 4; i++)
    {
        sum = 0;
        int m = omp_get_thread_num();
        if (m == 0)
        {
            for (j = 0; j < S*S / 4; j++)
            {
                for (k = 0; k < S; k++)sum += a[j / S][k] * b[k][j % S];
                x[j / S][j % S] = sum;
                printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                    j / S, j % S, x[j / S][j % S], omp_get_thread_num());
            }
        }
        else if (m == 1)
        {
            for (j = S*S/4; j < S*S / 2; j++)
            {
                for (k = 0; k < S; k++)sum += a[j / S][k] * b[k][j % S];
                x[j / S][j % S] = sum;
                printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                    j / S, j % S, x[j / S][j % S], omp_get_thread_num());
            }
        }
        else if (m == 2)
        {
            for (j = S*S / 2; j < 3*S*S / 4; j++)
            {
                for (k = 0; k < S; k++)sum += a[j / S][k] * b[k][j % S];
                x[j / S][j % S] = sum;
                printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                    j / S, j % S, x[j / S][j % S], omp_get_thread_num());
            }
        }
        else if (m == 3)
        {
            for (j = 3 * S*S / 4; j < S*S; j++)
            {
                for (k = 0; k < S; k++)sum += a[j / S][k] * b[k][j % S];
                x[j / S][j % S] = sum;
                printf("Matrix product x[%d, %d] = %d for thread=%d \n",
                    j / S, j % S, x[j / S][j % S], omp_get_thread_num());
            }
        }


        /*
        for (k = 0; k < S; k++)sum += a[i / S][k] * b[k][i % S];
        x[i / S][i % S] = sum;
        printf("Matrix product x[%d, %d] = %d for thread=%d \n",
            i / S, i % S, x[i / S][i % S], omp_get_thread_num());*/
    }

}
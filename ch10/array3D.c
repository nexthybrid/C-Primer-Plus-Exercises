/* 3D Arrays
    This file contains some basic definitnions and operations of 3D arrays.
    Use case of this is 3D point cloud data (x,y,z) with time. But the aim 
    of this file is to aquaintence you with 3D array syntax and best practices
    in C.
*/

#include <stdio.h>
#include <stdlib.h> // RAND_MAX, NULL
#include <time.h>   // srand, time, rand
#define TIME 2   // buffer size for time stamps
#define DIM 3    // x,y,z
#define N_BUF 15   // buffer size for points in point cloud

// define an enum to represent 'x' 'y' 'z' with integer 1, 2, 3.


void print_3d_array_VLA(int dim1, int dim2, int dim3, double (*array)[dim2][dim3]);
void copy_3d_array_arr_VLA(int dim1, int dim2, int dim3,
     double target[dim1][dim2][dim3], double source[dim1][dim2][dim3]);
void copy_3d_array_ptr_VLA(int dim1, int dim2, int dim3,
    double (*target)[dim2][dim3], double (*source)[dim2][dim3]);

int main()
{
    printf("Generating a random sequence of 3D point cloud history in time.\n");
    double pcd[TIME][DIM][N_BUF];
    for (int i = 0; i < TIME; i++){
        for (int j = 0; j < DIM; j++){
            for (int k = 0; k < N_BUF; k++){
                pcd[i][j][k] = rand() / (double)RAND_MAX;
            }
        }
    }
    print_3d_array_VLA(TIME, DIM, N_BUF, pcd);
    double target[TIME][DIM][N_BUF];
    // copy_3d_array_arr_VLA(TIME, DIM, N_BUF, target, pcd);
    copy_3d_array_ptr_VLA(TIME, DIM, N_BUF, target, pcd);   // alternative
    printf("After copying using copy_3d_array_arr_VLA, the copied new array is:\n");
    print_3d_array_VLA(TIME, DIM, N_BUF, target);
    return 0;
}

// 3d array copy, array notation with VLA
void copy_3d_array_arr_VLA(int dim1, int dim2, int dim3,
     double target[dim1][dim2][dim3], double source[dim1][dim2][dim3])
{
    for (int i = 0; i < dim1; i++)
        for (int j = 0; j < dim2; j++)
            for (int k = 0; k < dim3; k++)
                target[i][j][k] = source[i][j][k];
}

// 3d array copy, pointer notation with VLA
void copy_3d_array_ptr_VLA(int dim1, int dim2, int dim3,
    double (*target)[dim2][dim3], double (*source)[dim2][dim3])
{
    for (int i = 0; i < dim1; i++)
        for (int j = 0; j < dim2; j++)
            for (int k = 0; k < dim3; k++)
                *(*(*(target + i) + j) + k) = *(*(*(source + i) + j) + k);
}

void print_3d_array_VLA(int dim1, int dim2, int dim3, double (*array)[dim2][dim3])
{
    for (int i = 0; i < TIME; i++){
        printf("Time stamp i = %d\n", i);
        for (int j = 0; j < DIM; j++){
            switch (j){
                case 0:
                    printf("x:\t");
                    break;
                case 1:
                    printf("y:\t");
                    break;
                case 2:
                    printf("z:\t");
                    break;
                default:
                    printf("undefined:\t");
            }
            for (int k = 0; k < N_BUF; k++){
                printf("%.3lf  ", ((double (*)[dim2][dim3])array)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}


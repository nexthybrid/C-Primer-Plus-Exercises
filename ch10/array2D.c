/* This file aims to familiarize you with different syntax in 2D array
        In this file we DIY the declaration and initialization of a 2D array.
        One approach is erraneous, and one appraoch is proper but uses dynamic
        memory allocation.
*/

#include <stdio.h>
#include <stdlib.h> // malloc

void print_2d_array_VLA(int dim1, int dim2, int array[dim1][dim2]);

int main()
{
    /* Typical array declaration and initialization */
    int hippo[4][2] = {
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18}};
    printf("The hippo array defined using array notation:\n");
    print_2d_array_VLA(4, 2, hippo);
    /* (ERRANEOUS) DIY array declaration using pointer notations, somewhat 
        equivalent to 
            int zippo[4][2];
        except that the memory location of each zippo row may not be
        adjacent and in order to each other. A native array will nicely place
        the memory locations in a well-planned locale.
    */
    int zippo_row_0[2] = {21, 22}; // zippo_row_0 is of type int *
    int zippo_row_1[2] = {23, 24};
    int zippo_row_2[2] = {25, 26};
    int zippo_row_3[2] = {27, 28};
    int (* zippo)[2]; // type: pointer to two-int-sized object, int (*)[2]
    // cast and assign to zippo the pointer @ the first element of 
    // zippo_column_0 as a pointer to two-int-sized object
    zippo = (int (*)[2])zippo_row_0;
    printf("The zippo array (erraneously) defined using pointer notation:\n");
    print_2d_array_VLA(4, 2, zippo);
    /* DIY array declaration and initialization in a proper way:
        The problem with the approach above is that the memory locations
        of the four rows of zippo were not compactly aligned in memory.
        To do it properly, we need to allocate memory in a compact way.*/
    int * pMemory = (int *)malloc(4 * 2 * sizeof(int)); // malloc takes a compact memory chunk
    for (int i = 0; i < 4 * 2; i++)
        *(pMemory + i) = (i + 31);   // assign 31, 32, ..., 38 to the memory location
    int (* kippo)[2] = (int (*)[2])pMemory;
    printf("The kippo array (properly) defined using pointer notation:\n");
    print_2d_array_VLA(4, 2, kippo);
    return 0;
}

void print_2d_array_VLA(int dim1, int dim2, int array[dim1][dim2])
{
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++)
            printf("%d  ", array[i][j]);
        printf("\n");
    }
}
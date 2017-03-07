//
// Created by rencpawe on 07.03.17.
//

#include "Array2d.h"

int **Array2D(int n_rows, int n_columns)
{
    int** array= new int*[n_rows];

    for(int i=0; i< n_rows;i++)
    {
        int* array[i]= new int[n_columns];
    }
    return array;
}


void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i=0; i< n_rows;i++)
    {
        delete array[i];
    }
    delete [] array;
}
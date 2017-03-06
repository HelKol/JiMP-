//
// Created by ubuntu on 3/6/17.
//

#include "Array2d.h"

int **Array2D(int n_rows, int n_columns)
{
    int **array= new int* [n_rows];
    for(int i= 0;i<n_rows;i++)
    {
        array[i]= new int [n_columns];
    }
}
void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i= 0;i<n_rows;i++)
    {
        delete array[i];
    }
    delete [] array;

 }
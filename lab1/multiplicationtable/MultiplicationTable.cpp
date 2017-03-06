//
// Created by ubuntu on 3/6/17.
//

#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10])
{
    for (int i=1;i<=10;i++)
    {
        for(int d=1;d<=10;d++)
        {
            tab[i-1][d-1]= d*i;
        }
    }
}
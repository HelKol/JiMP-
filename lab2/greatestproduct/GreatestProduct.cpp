//
// Created by rencpawe on 07.03.17.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k)
{
    int a=-1,b=-1;
    //po obiekcie vector można iterować w pętli for
    for (int v : numbers) {
        if(v> a)
        {
            if(v>b)
            {
                b=v;
            }
            else
            {
                a=v;
            }
        }
    }
    return a*b;
}
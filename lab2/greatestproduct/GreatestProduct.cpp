//
// Created by rencpawe on 07.03.17.
//

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using std::vector;

void SortAbs(std::vector < int > num)
{
    int n=num.size();
    int pom, j;
    for(int i=1; i<n; i++)
    {

        pom = num[i];
        j = i-1;

        while(j>=0 && abs(num[j])>abs(pom))
        {
            num[j+1] = num[j];
            --j;
        }
        num[j+1] = pom;
    }
}


int GreatestProduct(const vector<int> &numbers, int k) {

    std::vector < int > num=numbers;


    sort( num.begin(), num.end() );
    std::vector<int> sorted = num;
    SortAbs(num);
    std::vector<int> sortedabs = num;

    int product1=1;
    int product2=1;
    if (k%2==1 && num[0]<0)
        product2=sorted[num.size()-1];

    for (int v=0;v<k;v++)
        product1=product1*sorted[num.size() - v -1];

    if (k%2==1 && num[0]<0)
    {
        for (int w=0;w<k-1;w++)
            product2=product2*sorted[ w ];
    } else {
    for (int w=0;w<k;w++)
        product2=product2*sorted[ w ];
    }
    if (product2>product1)
        return product2;
    else
        return product1;

}


//
// Created by Hela on 13.03.2017.
//

#include "GreatestProduct.h"
#include <vector>

int GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> thebiggest;
    std::vector<int> theleast;
    std::vector<int>::iterator it;
    for (int i =0;i<numbers.size();i++) {
        if (i<k) {
            int element = numbers[i];
            if (i==0){
                thebiggest.push_back(element);
                theleast.push_back(element);
            }
            else {
            for (int j=0;j<=i;j++)
                if (element>thebiggest[j])
                it=thebiggest.insert(it,j,element);



            else
        }
        }


    }





}

//
// Created by rencpawe on 07.03.17.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> tmp;
    int max= 1;
    for (int v : numbers) {
        tmp.push_back(v);
        if(tmp.size()== k){
            for (int v : tmp) {
                max*= v;
            }
        }
        if(tmp.size()>k){
            int to_erase= -1;
            for (int i=0;i<k;i++){
                int max_tmp= 1;
                for (int d=0; d<k;d++){
                    if(d==i){
                        max_tmp*= tmp[k];
                    } else {
                        max_tmp+= tmp[d];
                    }
                }
                if (max_tmp> max){
                    max= max_tmp;
                    to_erase= i;
                }
            }
            if (to_erase!=-1)
                tmp.erase(tmp.begin()+to_erase);
            else
                tmp.pop_back();
            }
        }


    return max;
}
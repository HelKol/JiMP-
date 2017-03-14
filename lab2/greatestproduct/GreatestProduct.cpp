//
// Created by Hela on 13.03.2017.
//

#include "GreatestProduct.h"
#include <vector>

int GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> thebiggest;
    std::vector<int> theleast;
    for (int i =0;i<=numbers.size();i++) {
        int element = numbers[i];
        if (i<k) {
            if (i == 0) {
                thebiggest.push_back(element);
                theleast.push_back(element);
            } else {
                int flag1=0;
                int flag2=0;
                if (element<*thebiggest.end()) {
                    thebiggest.push_back(element);
                    for (int j = 0; j <= i; j++) {
                        if (element < theleast[j] && !flag2) {
                            theleast.insert(theleast.begin() + j, numbers[i]);
                            flag2 = 1;
                        }

                    }
                }
                else if(element>*theleast.end()) {
                    theleast.push_back(element);
                    for (int j = 0; j <= i; j++) {
                        if (element > thebiggest[j] && !flag1) {
                            thebiggest.insert(thebiggest.begin()+j, numbers[i]);
                            flag1=1;

                        }
                    }
                }
                else{
                    for (int j = 0; j <= i; j++) {
                        if (element > thebiggest[j] && !flag1) {
                            thebiggest.insert(thebiggest.begin()+j, numbers[i]);
                            flag1=1;

                        }
                        if (element < theleast[j] && !flag2) {
                            theleast.insert(theleast.begin()+j,numbers[i]);
                            flag2=1;
                        }

                    }
                }
            }
        }
        else{ //rozwazamy przypadek jak i>k, czyli porownujemy z istniejacymi najwiekszmi liczbami i jesli trzeba je wyrzucamy
            if (thebiggest[k-1]<element) {
                thebiggest.pop_back();
                if (element<thebiggest[k-2])
                    thebiggest.push_back(element);
                else
                {
                    for (int l = k-2; l >= 0; l--) {
                        if (element < thebiggest[l]) {
                            thebiggest.insert(thebiggest.end()-l+1, numbers[i]);
                            break;
                        }
                    }
                }
            }
            if (element < theleast[k-1]) {
                theleast.pop_back();
                for (int n = 0; n <= k - 1; n++) {
                    if (element < theleast[n]) {
                        theleast[n + 1] = theleast[n];
                        theleast[n] = element;
                        }
                }

            }


        }

    }
    int product1=1;
    int product2=1;
    for (int v=0;v<k;v++)
        product1=product1*thebiggest[v];
    for (int w=0;w<k;w++)
        product2=product2*theleast[w];

    if (product2>product1)
        return product2;
    else
        return product1;
}

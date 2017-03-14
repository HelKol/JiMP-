//
// Created by Hela on 13.03.2017.
//

#include "GreatestProduct.h"
#include <vector>

int GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> thebiggest(k);
    std::vector<int> theleast(k);
    for (int i =0;i<numbers.size();i++) {
        int element = numbers[i];
        if (i<k) {
            if (i == 0) {
                thebiggest.push_back(element);
                theleast.push_back(element);
            } else {
                for (int j = 0; j <= i; j++) {
                    if (element > thebiggest[j]) {
                        thebiggest[j + 1] = thebiggest[j];
                        thebiggest[j] = element;
                    }
                    if (element < theleast[j]) {
                        theleast[j + 1] = theleast[j];
                        theleast[j] = element;
                    }


                }
            }
        }
        else{ //rozwazamy przypadek jak i>k, czyli porownujemy z istniejacymi najwiekszmi liczbami i jesli trzeba je wyrzucamy
            if (thebiggest[k-1]<element) {
                thebiggest.pop_back();
                for (int l = 0; l <= k - 1; l++) {
                    if (element > thebiggest[l]) {
                        thebiggest[l + 1] = thebiggest[l];
                        thebiggest[l] = element;
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
    for (int v : thebiggest)
        product1=product1*v;
    for (int w : theleast)
        product2=product2*w;

    if (product2>product1)
        return product2;
    else
        return product1;
}

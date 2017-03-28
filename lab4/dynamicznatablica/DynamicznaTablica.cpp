//
// Created by Hela on 28.03.2017.
//

#include "DynamicznaTablica.h"

void resize(int newSize){
    *wsk=new tab[newSize]; lenght=newSize;
};

void add(double element){
    int flag=0;
    for (int i=0;i<lenght;i++)
    {
        if (tab[i]==NULL){
            tab[i]=element;
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        resize(lenght+1);
        tab[lenght]=element;
    }
}
void print(){
    for (i=0;i<lenght;i++){
        cout<<tab[i]<<endl;
    }

}

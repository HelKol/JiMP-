//
// Created by Hela on 06.06.2017.
//
#include "TreeIterators.h"
#include <iostream>
using namespace tree;
using namespace std;

int main(){
    Tree<int> tree{5};
    tree.Insert(9);
    tree.Insert(8);
    tree.Insert(1);
    tree.Insert(3);
    Tree::InOrder()
}


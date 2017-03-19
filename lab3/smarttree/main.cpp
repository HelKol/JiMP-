//
// Created by xxx on 19.03.17.
//
#include <iostream>
#include "SmartTree.h"
using namespace datastructures;

int main(void){
    auto root = CreateLeaf(99);
    root = InsertLeftChild(move(root), CreateLeaf(100));
    root = InsertRightChild(move(root), CreateLeaf(88));

    std::cout<<DumpTree(root);
}

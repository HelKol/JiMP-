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
    root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(897));

    std::cout<<DumpTree(root)<<std::endl;
    std::cout<<DumpTree(RestoreTree(DumpTree(root)))<<std::endl;
}

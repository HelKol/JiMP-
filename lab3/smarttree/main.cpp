//
// Created by xxx on 19.03.17.
//
#include <iostream>
#include "SmartTree.h"
using namespace datastructures;

int main(void){
    auto root = CreateLeaf(1);
    root = InsertLeftChild(move(root), CreateLeaf(2));
    root = InsertRightChild(move(root), CreateLeaf(3));
    root->left = InsertLeftChild(move(root->left), CreateLeaf(4));
    root->left = InsertRightChild(move(root->left), CreateLeaf(5));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(6));
    root->right = InsertRightChild(move(root->right), CreateLeaf(7));

    Pt(root);
    std::cout<<std::endl<<DumpTree(move(root));
}

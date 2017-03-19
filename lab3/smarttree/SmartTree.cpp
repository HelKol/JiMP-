//
// Created by xxx on 19.03.17.
//
#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"

namespace datastructures{
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        return std::unique_ptr<SmartTree>(new SmartTree(value));
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if(left_subtree->left!= nullptr){
            auto tmp= move(left_subtree->left);
            left_subtree->left= move(tree);
            tree->left= move(tmp);
        } else {
            left_subtree->left= move(tree);
        }

        return left_subtree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        auto tmp= move(right_subtree->left);
        right_subtree->left= move(tree);
        tree->left= move(tmp);
        return std::unique_ptr<SmartTree>();
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {

    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        if(tree->left!= nullptr) DumpTree(tree->left);
        if(tree->right!= nullptr) DumpTree(tree->right);
//        tree.release();
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        return std::unique_ptr<SmartTree>();
    }
}
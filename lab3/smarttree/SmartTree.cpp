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
        if(tree->left!= nullptr) {
            auto tmp = move(tree->left);
            left_subtree->left = move(tmp);
        }
        tree->left= move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if(tree->right!= nullptr) {
            auto tmp = move(tree->right);
            right_subtree->right = move(tmp);
        }
        tree->right= move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if(unique_ptr!= nullptr){
            PrintTreeInOrder(unique_ptr->left, out);
            *out<<unique_ptr->value<<", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string output;
        if(tree->left!= nullptr) {
            output+= DumpTree(tree->left)+" ";
        } else {
            output+= "[none]";
        }
        if (tree->right!= nullptr){
            output+= DumpTree(tree->right);
        } else{
            output+=" [none]";
        }

        output="["+std::to_string(tree->value)+" "+output+"]";
        return output;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        return std::unique_ptr<SmartTree>();
    }
}
//
// Created by xxx on 19.03.17.
//
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <memory>
#include "SmartTree.h"

namespace datastructures{
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        return std::unique_ptr<SmartTree>(new SmartTree(value));
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if(tree== nullptr) return nullptr;
        if(tree->left!= nullptr) {
            auto tmp = move(tree->left);
            left_subtree->left = move(tmp);
        }
        tree->left= move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if(tree== nullptr) return nullptr;
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
    void Pt(const std::unique_ptr<SmartTree> &unique_ptr) {
        if(unique_ptr!= nullptr){
            std::cout<<unique_ptr->value<<", ";
            Pt(unique_ptr->left);
            Pt(unique_ptr->right);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string output;
        if(tree->left!= nullptr) {
            output+= DumpTree(tree->left)+" ";
        } else {
            output+= "[none] ";
        }
        if (tree->right!= nullptr){
            output+= DumpTree(tree->right);
        } else{
            output+= "[none]";
        }

        output="["+std::to_string(tree->value)+" "+output+"]";
        return output;
    }

    int ToInt(std::string value) {
        std::stringstream ss;
        int output;
        ss << value;
        ss >> output;
        return output;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        std::string tmp;
        std::string tmp2= tree;
        int iterator= 0;
        for(int i=0;i <tmp2.length();){
            if(tmp2[i]=='[' and tmp[i+1]!='n'){
                iterator++;
                tmp2.erase(0);
                while(tmp2[0]>47 and tmp2[0]<58){
                    tmp+= tree[0];
                    tmp2.erase(0);
                }
            }
            tmp2.erase(0);
        }

        auto root = CreateLeaf(ToInt(tmp));
//        root->left = RestoreTree(leftchild);
//        root->right = RestoreTree(rightchild);


        return root;
    }
}
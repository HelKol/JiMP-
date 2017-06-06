//
// Created by Hela on 06.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include <iostream>
namespace tree{
    template<class T>
    class Tree {
    public:
        Tree():depth_(0),size_(0){};
        Tree(const T &a) : key_(a),depth_(1),size_(1) {};
        void Insert(const T &e) {
            size_++;
            size_t tmp= size_;
            size_t i=0;
            while(tmp>0){
                tmp/=2;
                i++;
            }
            depth_= i;
            Tree* a = this;
            while (1) {
                if (size_==1){
                    a->root_= std::make_unique<Tree>(e);
                    a->left_= nullptr;
                    a->right_= nullptr;
                    break;
                }
                if (e < a->key_) {
                    if (a->left_ == nullptr) {
                        a->left_ = std::make_unique<Tree>(e);
                        break;
                    }
                    a= a->left_.get();
                } else {
                    if (a->right_ == nullptr) {
                        a->right_ = std::make_unique<Tree>(e);
                        break;
                    }
                    a= a->right_.get();
                }
            }


        }

        bool Find(const T &e) {

        }
        void static InOrder(const std::unique_ptr<Tree> a) {
            if (a != nullptr) {
                InOrder(a->left_);
                std::cout << a->key_ << std::endl;
                InOrder(a->right_);
            }
        }
        T Value() {
            return key_;
        }

        size_t Depth() {
            return depth_;
        }

        size_t Size() {
            return size_;
        }

    private:
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        std::unique_ptr<Tree> root_;

        T key_;

        size_t size_;
        size_t depth_;
    };



}

#endif //JIMP_EXERCISES_TREEITERATORS_H

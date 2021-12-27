#include <iostream>
#include <string>
#include <vector>

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

class BinaryTree
{
public:
    int value;
    BinaryTree * left;
    BinaryTree * right;

    BinaryTree();
    BinaryTree(int &);
    BinaryTree(const BinaryTree &);
    BinaryTree(const int &, BinaryTree * = NULL, BinaryTree * = NULL);
    ~BinaryTree();

    BinaryTree * getLeftTree() const;
    BinaryTree * getRightTree() const;

    int getValue() const;
};
#endif
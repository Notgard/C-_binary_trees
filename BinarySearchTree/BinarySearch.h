#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__
class Node;
class BinarySearch
{
public:

    Node * root;

    BinarySearch();
    BinarySearch(Node *);
    BinarySearch(float *);
    BinarySearch(BinarySearch *);

    void insert(float *);
    bool search(float *) const;
    bool deleteNode(float *, BinarySearch *);

    float * getValue() const;
    int getHeight() const;

    bool isBalanced() const;
    void balancedInsert(float *);

    BinarySearch * getLeftTree() const;
    BinarySearch * getRightTree() const;

    void static treeSort(float arr[], const int&);
    void sort(float [], int &i);
    void toString(const std::string & = "", bool isLeft = true) const;
};
#endif
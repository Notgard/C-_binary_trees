#include <iostream>
#include <string>

#ifndef __NODE_H__
#define __NODE_H__
class BinarySearch;
class Node
{
public:
    float * value;
    BinarySearch * leftChild;
    BinarySearch * rightChild;

    Node();
    Node(float *);
    Node(float *, BinarySearch *, BinarySearch *);
    float * getValue() const;
    void setValue(float *);
    BinarySearch * getLeftChild() const;
    BinarySearch * getRightChild() const;
    void insert(Node *, BinarySearch *);
    void remove(Node *, float *);
};

#endif
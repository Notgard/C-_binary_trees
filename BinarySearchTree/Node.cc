#include "Node.h"

using namespace std;


Node::Node()
{
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->value = NULL;
}


Node::Node(float * value)
{
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->value = value;
}

Node::Node(float * value, BinarySearch * leftChild, BinarySearch * rightChild)
{
    this->value = value;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}

float * Node::getValue() const
{
    return this->value;
}

void Node::setValue(float *value)
{
    this->value = value;
}
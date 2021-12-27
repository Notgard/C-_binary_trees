#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(int & value)
{
    this->value = value;
}

BinaryTree::BinaryTree() 
{
    this->value = rand() % 10 + 1;
    int left = rand() % 10 + 1;
    this->left = new BinaryTree(left);
    int right = rand() % 10 + 1;
    this->right = new BinaryTree(right);
}

BinaryTree::BinaryTree(const BinaryTree & tree)
{
    this->value = tree.value;
    this->left = tree.left;
    this->right = tree.right;
}

BinaryTree::BinaryTree(const int & value, BinaryTree * left, BinaryTree * right)
{
    this->value = value;
    if (this->left != NULL)
    {
        delete[] this->left;
    }
    
    else
    {
        this->left = left;
    }

    if (this->right != NULL)
    {
        delete[] this->right;
    }
    
    else
    {
        this->right = right;
    }
}

BinaryTree::~BinaryTree()
{
    cout << "Destruction of BinaryTree" << endl;
}

BinaryTree * BinaryTree::getLeftTree() const
{
    return this->left;
}

BinaryTree * BinaryTree::getRightTree() const
{
    return this->right;
}

int BinaryTree::getValue() const
{
    return this->value;
}

int main(int argc, char**)
{
    BinaryTree * left = new BinaryTree(2, new BinaryTree(1), new BinaryTree(4, new BinaryTree(3), new BinaryTree(5)));
    BinaryTree * right = new BinaryTree(2, new BinaryTree(8), new BinaryTree(12));

    BinaryTree * racine = new BinaryTree(6, left, right);

    int leftValue = racine->getLeftTree()->getValue(); //
    int rightValue = racine->getRightTree()->getValue(); //
    int rightsLeftTreeValue = racine->getRightTree()->getLeftTree()->getValue();
    int rightsRightTreeValue = racine->getRightTree()->getRightTree()->getValue();

    int leftsLeftTreeValue = racine->getLeftTree()->getLeftTree()->getValue();
    int leftsRightTreeValue = racine->getLeftTree()->getRightTree()->getValue();

    cout << "Left Tree Value: " << leftValue << endl << "Right Tree Value: " << rightValue << endl;
    cout << "Right Tree's left tree's value: " << rightsLeftTreeValue << endl;
    cout << "Right Tree's right tree's value: " << rightsRightTreeValue << endl;

    cout << "Left Tree's left tree's value: " << leftsLeftTreeValue << endl;
    cout << "Left Tree's right tree's value: " << leftsRightTreeValue << endl;
    return 0;
}
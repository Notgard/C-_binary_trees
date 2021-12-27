#include "BinarySearch.h"
#include "Node.h"
using namespace std;

BinarySearch::BinarySearch()
{
    this->root = NULL;
}

BinarySearch::BinarySearch(Node *root)
{
    this->root = root;
}

float *BinarySearch::getValue() const
{
    return this->root->value;
}

BinarySearch *BinarySearch::getLeftTree() const
{
    return this->root->leftChild;
}

BinarySearch *BinarySearch::getRightTree() const
{
    return this->root->rightChild;
}

BinarySearch::BinarySearch(BinarySearch *node)
{
    if (root == NULL && node != NULL)
    {
        this->root = new Node(node->root->value, node->root->leftChild, node->root->rightChild);
    }
}

BinarySearch::BinarySearch(float *value)
{
    this->root = new Node(value);
}

bool BinarySearch::search(float *searchedValue) const
{

    if (*searchedValue == *this->getValue())
    {
        return true;
    }

    if ((*searchedValue < *this->getValue()) && (this->root->leftChild->getValue() != NULL))
    {
        return this->root->leftChild->search(searchedValue);
    }

    if ((*searchedValue > *this->getValue()) && (this->root->rightChild->getValue() != NULL))
    {
        return this->root->rightChild->search(searchedValue);
    }

}

#if 0
bool BinarySearch::deleteNode(float * value, BinarySearch * root) {
    if (root == NULL) {
        return false;
    }
    else if (root->getValue() == value)
    {
        BinarySearch * tree = new BinarySearch(root);
    }
}
#endif

void BinarySearch::insert(float *value)
{
    if (this->root == NULL)
    {
        this->root = new Node(value);
    }
    else if (*value == *this->root->value)
    {
        cout << "Value already in tree";
    }
    else if (*value < *this->getValue())
    {
        if (this->getLeftTree() != NULL)
        {
            this->getLeftTree()->insert(value);
        }
        else
        {
            this->root->leftChild = new BinarySearch(value);
        }
    }
    else if (*value > *this->getValue())
    {
        if (this->getRightTree() != NULL)
        {
            this->getRightTree()->insert(value);
        }
        else
        {
            this->root->rightChild = new BinarySearch(value);
        }
    }
}

void BinarySearch::toString(const string &prefix, bool isLeft) const
{
    // Parcours Infixe 
    cout << prefix;
    if (this->root == nullptr) 
    {
        cout << "Empty Binary Search Tree" << endl;
        cout << "├──";
        cout << "NULL" << endl;
        cout << "│  " << "  └──" << "NULL" << endl;
        cout << "│  " <<"  └──" << "NULL" << endl;
    }
    else
    {
        cout << (isLeft ? (this->root->rightChild != nullptr ? "├──" : "└──") : "└──");
        cout << *this->root->value << endl;

        if (this->root->leftChild != nullptr)
        {
            this->root->leftChild->toString(prefix + (isLeft && root->rightChild != nullptr ? "│  " : "   "), true);
        }
        if (this->root->rightChild != nullptr)
        {
            this->root->rightChild->toString(prefix + (isLeft && root->rightChild != nullptr ? "│  " : "   "), false);
        }
    }
}

int BinarySearch::getHeight() const
{
    if (this->getValue() == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight;
        int rightHeight;
        if (this->root->leftChild != nullptr)
            {leftHeight = this->getLeftTree()->getHeight();}
        else
        {
            leftHeight = -1;
        }
        if (this->root->rightChild != nullptr)
            {rightHeight = this->getRightTree()->getHeight();}
        else
        {
            rightHeight = -1;
        }
        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}

bool BinarySearch::isBalanced() const
{
    if (this->getValue() == nullptr)
    {
        return true;
    }
    else
    {
        //Check if branch is accessible for the balance
        bool leftBalance;
        bool rightBalance;
        if (this->root->leftChild != nullptr)
        {
            leftBalance = this->getLeftTree()->isBalanced();
        }
        else
        {
            leftBalance = true;
        }
        if (this->root->rightChild != nullptr)
        {
            rightBalance = this->getRightTree()->isBalanced();
        }
        else
        {
            rightBalance = true;
        }
        //Check if branch is accessible for the height
        int leftHeight;
        int rightHeight;

        if (this->root->leftChild != nullptr)
            {leftHeight = this->getLeftTree()->getHeight();}
        else
        {
            leftHeight = 0;
        }
        if (this->root->rightChild != nullptr)
            {rightHeight = this->getRightTree()->getHeight();}
        else
        {
            rightHeight = 0;
        }
        return (
            (abs(leftHeight - rightHeight) <= 1) && 
            (leftBalance && rightBalance)
        );
    }
}

void BinarySearch::treeSort(float arr[], const int &size)
{
    BinarySearch * tree = new BinarySearch();
    //make copy of the original array to generate binary search tree
    vector<float> copy(arr, arr + size);

    for (unsigned int i = 0; i < size; i++)
    {
        float * val = &copy[i];
        tree->insert(val);
    }

    tree->toString(" ");
    string balance = tree->isBalanced() == false ? "No it's not balanced" : "The tree is balanced";
    cout << balance << endl;

    int height = tree->getHeight();
    cout << "Current Height: " << height << endl;
    cout << "Sorting..." << endl;

    int i = 0;
    //Use the original in the sorting and add the tree values in order
    tree->sort(arr, i);
    //Delete the tree memory after use
    delete tree;
}

void BinarySearch::sort(float arr[], int &i)
{
    if (this->root != NULL)
    {
        if (this->root->leftChild != nullptr)
            this->root->leftChild->sort(arr, i);

        arr[i++] = *this->getValue();

        if (this->root->rightChild != nullptr)
            this->root->rightChild->sort(arr, i);
    }
}

//TODO
void BinarySearch::balancedInsert(float * value)
{
    if (this->root == NULL)
    {
        this->root = new Node(value);
    }
    else if (*value == *this->root->value)
    {
        cout << "Value already in tree";
    }
    else if (*value < *this->getValue())
    {
        if (this->getLeftTree() != NULL)
        {
            if (this->getLeftTree()->isBalanced() == true)
            {
                // On inverse les deux valeur afin de garder
                // l'intégrité de l'arbre binaire
                float * copy = this->getValue();
                float copyValue = *copy;
                this->root->setValue(value);
                this->getLeftTree()->insert(&copyValue);
            }
            else {
                this->getLeftTree()->insert(value);
            }
        }
        else
        {
            if (this->getRightTree()->isBalanced() == true)
            {
                float * copy = this->getValue();
                float copyValue = *copy;
                this->root->setValue(value);
                this->getRightTree()->insert(&copyValue);
            }
            else {
                this->getRightTree()->insert(value);
            }
        }
    }
    else if (*value > *this->getValue())
    {
        if (this->getRightTree() != NULL)
        {
            this->getRightTree()->insert(value);
        }
        else
        {
            this->root->rightChild = new BinarySearch(value);
        }
    }
}

int main(int argc, char **argv)
{
    float rootValue = 23.9;
    float leftValue = 14.2;
    float rightValue = 39.7;
    BinarySearch *searchTree = new BinarySearch(new Node(&rootValue, new BinarySearch(new Node(&leftValue)), new BinarySearch(new Node(&rightValue))));
    cout << "Root Value : " << *searchTree->root->value << endl;
    cout << "-----------------------------------------------------" << endl;
    searchTree->toString(" ");
    cout << "-----------------------------------------------------" << endl;
    float insertValue1 = 400.1;
    searchTree->insert(&insertValue1);
    float insertValue2 = 12.1;
    searchTree->insert(&insertValue2);
    float insertValue3 = 11.2;
    searchTree->insert(&insertValue3);
        float insertValue4 = 22.5;
    searchTree->insert(&insertValue4);
    searchTree->toString(" ");
    cout << "---------------------Empty tree-------------------------" << endl;
    BinarySearch * emptyTree = new BinarySearch();
    emptyTree->toString();
    cout << "-------------------Current Height----------------------" << endl;
    int height = searchTree->getHeight();
    cout << height << endl;
    cout << "----------------Is the current tree balanced ?---------------" << endl;
    string balance = searchTree->isBalanced() == false ? "No it's not balanced" : "The tree is balanced";
    cout << balance << endl;
    cout << "---------------------Tree sort with float array-----------------------" << endl;
    float arr[] = {5.2, 4.4, 7.1, 2.8, 11.1};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    BinarySearch::treeSort(arr, n);
    cout << "[ ";
    for (unsigned int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << "]" << endl;
    cout << "-------------------Search for 400.1----------------------" << endl;
    float valueSearched = 400.1;
    string found = (searchTree->search(&valueSearched) == true) ? "Value found!" : "Value not found...";
    cout << found << endl;
    cout << "-------------------Search for not existent value----------------------" << endl;
    float val = 64654654.222;
    string found_ = (searchTree->search(&val) == true) ? "Value found!" : "Value not found...";
    cout << found_ << endl;
    return 0; //
}
#include <iostream>

using namespace std;

class BinTree
{
private:
    struct Node
    {
        int data;
        Node* leftchild;
        Node* rightchild;

        Node(int data)
        {
            this->data = data;
            leftchild = nullptr;
            rightchild = nullptr;
        }
    };
    Node* head;

    void CopyTree(Node*& oldtree, Node* const& newtree)
    {
        if (newtree == nullptr)
            return;
        oldtree = new Node(newtree->data);
        CopyTree(oldtree->leftchild, newtree->leftchild);
        CopyTree(oldtree->rightchild, newtree->rightchild);
    }

    void DeleteSub(Node* root)
    {
        if (root->leftchild != nullptr)
            DeleteSub(root->leftchild);
        if (root->rightchild != nullptr)
            DeleteSub(root->rightchild);
        delete root;
    }

    void Label(Node* n)
    {
        cout << n->data << " ";
    }

    Node* Parent(Node* const root, Node* current)
    {
        Node* res;
        if (current->leftchild != root && current->leftchild != nullptr)
            res = Parent(root, current->leftchild);
        if (res->leftchild == root)
            return res;

        if (current->rightchild != root && current->rightchild != nullptr)
            res = Parent(root, current->rightchild);
        if (res->rightchild == root)
            return res;
        return nullptr;
    }

    Node* MostLeftChild(Node* n)
    {
        return n->leftchild;
    }

    Node* RightSibling(Node* n)
    {
        return n->rightchild;
    }

    Node* Root()
    {
        return head;
    }

    void Push(Node* root, int data)
    {
        if (root->data > data)
            if (root->leftchild != nullptr)
                Push(root->leftchild, data);
            else
            {
                root->leftchild = new Node(data);
                return;
            }
        if (root->data < data)
            if (root->rightchild != nullptr)
                Push(root->rightchild, data);
            else
            {
                root->rightchild = new Node(data);
                return;
            }
        return;
    }

    void PreOrder(Node* root)
    {
        if (root != nullptr)
        {
            Label(root);
            if (root->leftchild != nullptr)
                PreOrder(root->leftchild);
            if (root->rightchild != nullptr)
                PreOrder(root->rightchild);
        }
    }

public:

    BinTree(const int* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Push(arr[i]);
        }
    }

    BinTree(const BinTree& bintree)
    {
        CopyTree(this->head, bintree.head);
    }

    ~BinTree()
    {
        clear();
    }

    void Push(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
        }
        Push(head, data);
    }

    void clear()
    {
        DeleteSub(head);
        head = nullptr;
    }

    void print()
    {
        PreOrder(head);
        cout << endl;
    }
};

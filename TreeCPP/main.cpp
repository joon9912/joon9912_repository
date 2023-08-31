#include <iostream>
using namespace std;

typedef
struct node {
    struct node *left, *right;
    int value;
} Node;

class BinarySearchTree {
    Node *root;

    void removeAll(Node *node);
    void inOrder(Node *cur);
    Node *searchMaxNode(Node *node);
    Node *removeSequence(Node *node, int _value);
public:
    BinarySearchTree():root(nullptr) { }
    ~BinarySearchTree();

    void addNode(int value);
    bool searchValue(int value);
    void removeNode(int value);
    void show();
};

void BinarySearchTree::show() {
    inOrder(root);
}

void BinarySearchTree::removeAll(Node *node) {
    if (node != nullptr) {
        removeAll(node->left);
        removeAll(node->right);
        // cout << "delete " << node->value << "\n";
        delete node;
    }
}

BinarySearchTree::~BinarySearchTree() {
    removeAll(root);
}

void BinarySearchTree::inOrder(Node *cur) {
    if (cur != nullptr) {
        inOrder(cur->left);
        cout << cur->value << endl;
        inOrder(cur->right);
    }
}

Node* BinarySearchTree::searchMaxNode(Node *node) {
    if (node == NULL)
        return NULL;
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

void BinarySearchTree::addNode(int value) {
    Node *node = new Node();
    Node *tmpRoot = nullptr;

    node->value = value;
    if (root == nullptr)
        root = node;
    else {
        Node *ptr = root;
        while (ptr != nullptr) {
            tmpRoot = ptr;
            if (node->value < ptr->value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (node->value < tmpRoot->value)
            tmpRoot->left = node;
        else
            tmpRoot->right = node;
    }
}

Node *BinarySearchTree::removeSequence(Node *node, int _value) {
    if (node == nullptr)
        return node;
    else if (node->value > _value)
        node->left = removeSequence(node->left, _value);
    else if (node->value < _value)
        node->right = removeSequence(node->right, _value);
    else {
        Node *ptr = node;
        if (node->right == nullptr && node->left == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->right == nullptr) {
            node = node->left;
            delete ptr;
        }
        else if (node->left == nullptr) {
            node = node->right;
            delete ptr;
        }
        else {
            ptr = searchMaxNode(node->left);
            node->value = ptr->value;
            node->left = removeSequence(node->left, ptr->value);
        }
        return node;
    }
}

void BinarySearchTree::removeNode(int value) {
    Node *ptr = root;
    removeSequence(ptr, value);
}

bool BinarySearchTree::searchValue(int value) {
    Node *ptr = root;
    Node *tmpRoot = nullptr;

    while (ptr != nullptr) {
        if (ptr->value == value) {
            cout << value << " Found\n";
            return true;
        }
        else if (ptr->value > value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    cout << value << " not Found\n";

    return false;
}

int main() {
    BinarySearchTree *BST = new BinarySearchTree();

    BST->addNode(10);
    BST->addNode(6);
    BST->addNode(2);
    BST->addNode(3);
    BST->addNode(9);
    BST->addNode(13);
    BST->addNode(1);
    BST->addNode(22);
    BST->addNode(17);

    BST->show(); cout << "\n";
    BST->searchValue(4);
    BST->searchValue(17);
    BST->searchValue(22);

    BST->show();

    delete BST;

    return 0;
}
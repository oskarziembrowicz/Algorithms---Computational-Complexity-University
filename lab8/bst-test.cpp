#include <iostream>

using namespace std;

template <typename T> class BST {
    struct Node {
        T value;
        Node* left;
        Node* right;
    };
public:
    BST() {
        this->treeSize = 0;
        this->root = NULL;
    }

    void insert(T value) {
        insert(root, value);
    }
    T find(T value) {
        return find(root, value);
    }
    void print() {
        print(root);
    }

private:
    int treeSize;
    Node* root;

    void insert(Node* n, T value) {
        if (n == NULL) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            this->treeSize++;
        } else {
            if (n->value >= value) {
                insert(n->left, value);
            } else {
                insert(n->right, value);
            }
        }
    }

    T find(Node* n, T value) {
        if (n == NULL) {
            return NULL;
        }

        if (n->value == value) {
            return n->value;
        } else if (n->value > value) {
            return find(n->left, value);
        } else {
            return find(n->right, value);
        }
    }

    void print(Node* n) {
        if (n == NULL) {
            return;
        }

        print(n->left);
        cout << n->value << "\n";
        print(n->right);
    }
};

int main() {
    BST<int> tree;

    tree.insert(5);
	tree.insert(4);
	tree.insert(7);
	tree.insert(10);
	tree.insert(1);
	tree.insert(2);

    tree.print();


    return 0;
}
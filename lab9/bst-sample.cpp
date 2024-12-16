#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = right = NULL;
    }
};

Node* insert(int key, Node* currentNode) {
        if (key < currentNode->value) {
            if (currentNode->left) {
                return insert(key, currentNode->left);
            } else {
                currentNode->left = new Node(key);
                // Splay()
                return currentNode->left;
            }
        } else if (key > currentNode->value) {
            if (currentNode->right) {
                return insert(key, currentNode->right);
            } else {
                currentNode->right = new Node(key);
                // Splay()
                return currentNode->right;
            }
        } else {
            // Keys are equal
            // Add value
            // Splay
        }
}

Node* find(int key, Node* currentNode) {
        if (!currentNode) {
            return NULL;
        }
        if (currentNode->value == key) {
            return currentNode;
        } else if (key < currentNode->value) {
            find(key, currentNode->left);
        } else {
            find(key, currentNode->right);
        }
}

void printTree(Node* currentNode) {
        if (!currentNode) {
            return;
        }
        printTree(currentNode->left);
        cout << currentNode->value << " ";
        printTree(currentNode->right);
    }

int main() {

    // Dummy data --------------------------
    Node* node = new Node(5);
    // node->left = new Node(3);
    // node->right = new Node(10);
    // node->left->left = new Node(1);
    // node->left->right = new Node(4);
    // node->right->right = new Node(12);
    // -------------------------------------

    insert(3, node);
    insert(10, node);
    insert(1, node);
    insert(4, node);
    insert(12, node);

    printTree(node);
    cout << "\n";

    Node* result = find(4, node);
    if (result) {
        cout << result->value << "\n";
    } else {
        cout << "Node not found\n";
    }

    return 0;
}
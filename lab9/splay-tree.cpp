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

class SplayTree {
    public:
};

Node* rotateRight(Node *target) {
    // Left child of the target will become the new parent Node
    Node* leftChild = target->left;
    target->left = leftChild->right;
    leftChild->right = target;
    return leftChild;
}

Node* rotateLeft(Node *target) {
    // Right child of the target will become the new parent Node
    Node* rightChild = target->right;
    target->right = rightChild->left;
    rightChild->left = target;
    return rightChild;
}

Node* splay(Node* root, int key) {
    if (root == NULL || root->value == key) {
        return root;
    }

    // Key is to the left
    if (key < root->value) {
        if (!root->left) {
            // Left does not exist
            // Key is not in tree
            return root;
        }
        // The key is double to the left (zig-zig)
        if (key < root->left->value) {
            // Bring node with key to root->left->left
            root->left->left = splay(root->left->left, key);

            // First rotation to set root->left as root
            root = rotateRight(root);
        } else if (key > root->left->value) {
            // The key is to the left then right (zig-zag)
            // Bring node with key to root->left->right
            root->left->right = splay(root->left->right, key);

            // First rotation to set root->left->right as root->left
            if (root->left->right) {
                root->left = rotateLeft(root->left);
            }
        } else {
            // Here do the second rotation
            if (root->left) {
                return rotateRight(root);
            } else {
                return root;
            }
        }
    } else {
        // Key is to the right
        if (!root->right) {
            return root;
        }
        // The key is to the right then left (zag-zig)
        if (key < root->right->value) {
            root->right->left = splay(root->right->left, key);

            if (root->right->left) {
                root->right = rotateRight(root->right);
            }
        } else if (key > root->right->value) {
            // The key is double to the right (zag-zag)
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        } else {
            if (root->right) {
                return rotateLeft(root);
            } else {
                return root;
            }
        }
    }
}

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->value) {
        // cout << "Went left\n";
        if (root->left) {
            // cout << "Went deep\n";
            root->left = insert(root->left, key);
        } else {
            root->left = new Node(key);
            // cout << "Added\n";
            // splay(root->left, key);
            // return root->left;
        }
    } else if (key > root->value) {
        // cout << "Went right\n";
        if (root->right) {
            // cout << "Went deep\n";
            root->right = insert(root->right, key);
        } else {
            root->right = new Node(key);
            // cout << "Added\n";
            // Splay()
            // return root->right;
        }
    } else {
        // cout << "Was equal to existing node\n";
        return root;
        // Keys are equal
        // Add value
        // Splay
    }
    return splay(root, key);
}

Node* find(int key, Node* root) {
    return splay(root, key);
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
    Node* root = insert(NULL, 5);
    // node->left = new Node(3);
    // node->right = new Node(10);
    // node->left->left = new Node(1);
    // node->left->right = new Node(4);
    // node->right->right = new Node(12);
    // -------------------------------------

    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 12);

    printTree(root);
    cout << "\n";

    Node* result = find(12, root);
    if (result) {
        cout << result->value << "\n";
    } else {
        cout << "Node not found\n";
    }

    return 0;
}
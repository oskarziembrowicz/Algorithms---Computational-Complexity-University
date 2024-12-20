#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    int age;
    string occupation;
    Person(int age, string occupation) {
        this->age = age;
        this->occupation = occupation;
    }

    Person operator+(const Person& p) {
        Person person(this->age+p.age, p.occupation);
        return person;
    }
};

std::ostream &operator<<(std::ostream &os, Person const &m) { 
    return os << "[" << m.age << "," << m.occupation << "]";
}

template <typename T>
class SplayTree {
private:
    class Node {
    public:
        string key;
        T* value;
        Node* left;
        Node* right;

        Node(string key, T* value) {
            this->key = key;
            this->value = value;
            left = right = NULL;
        }
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

    Node* splay(Node* root, string key) {
        if (root == NULL || root->key == key) {
            return root;
        }

        // Key is to the left
        if (key < root->key) {
            if (!root->left) {
                // Left does not exist
                // Key is not in tree
                return root;
            }
            // The key is double to the left (zig-zig)
            if (key < root->left->key) {
                // Bring node with key to root->left->left
                root->left->left = splay(root->left->left, key);

                // First rotation to set root->left as root
                root = rotateRight(root);
            } else if (key > root->left->key) {
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
            if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);

                if (root->right->left) {
                    root->right = rotateRight(root->right);
                }
            } else if (key > root->right->key) {
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

    Node* insert(Node* root, string key, T* value) {
        if (!root) {
            return new Node(key, value);
        }

        if (key < root->key) {
            if (root->left) {
                root->left = insert(root->left, key, value);
            } else {
                root->left = new Node(key, value);
            }
        } else if (key > root->key) {
            if (root->right) {
                root->right = insert(root->right, key, value);
            } else {
                root->right = new Node(key, value);
            }
        } else {
            // Keys are equal
            // Add value
            *(root->value) = *(root->value) + *value;
        }
        return splay(root, key);
    }

    Node* find(Node* root, string key) {
        return splay(root, key);
    }

    void printTree(Node* currentNode) {
        if (!currentNode) {
            return;
        }
        printTree(currentNode->left);
        cout << *currentNode->value << " ";
        printTree(currentNode->right);
    }

    Node* root;
public:

    SplayTree() {
        root = NULL;
    }

    void insert(string key, T* value) {
        root = insert(root, key, value);
    }

    T* find(string key) {
        root = find(root, key);
        return root->value;
    }

    void printTree() {
        printTree(root);
    }
};

int main() {

    // People tree:
    SplayTree<Person>* peopleTree = new SplayTree<Person>();
    peopleTree->insert("Adam", new Person(25, "car mechanic"));
    peopleTree->insert("Eva", new Person(33, "attourney"));
    peopleTree->insert("Bob", new Person(45, "gardener"));
    peopleTree->insert("Jim", new Person(22, "student"));
    peopleTree->insert("Steve", new Person(55, "blacksmith"));
    peopleTree->insert("Steve", new Person(56, "butcher"));

    peopleTree->printTree();
    cout << "\n";

    Person* jim_data = peopleTree->find("Jim");
    cout << *jim_data << "\n";

    // Int tree
    SplayTree<int>* integerTree = new SplayTree<int>();
    integerTree->insert("Five", new int(5));
    integerTree->insert("Ten", new int(10));
    integerTree->insert("Twenty Two", new int(22));
    integerTree->insert("One", new int(1));
    integerTree->insert("One", new int(1));

    integerTree->printTree();
    cout << "\n";

    // Node* result = find(12, root);
    // if (result) {
    //     cout << result->value << "\n";
    // } else {
    //     cout << "Node not found\n";
    // }

    return 0;
}
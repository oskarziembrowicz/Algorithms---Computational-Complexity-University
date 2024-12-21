#include <iostream>
#include <string>

using namespace std;

/*
Budujemy dwa drzewa:
    1. Drzewo posortowane pod względem zawodów
        a) Każdy węzeł to:
            - Nazwa zawodu
            - Drzewo dla zawodu posortowane względem objawów, gdzie każdy węzeł to:
                * Nazwa objawu
                * Ilość chłopów z danym objawem o danym zawodzie
    2. Drzewo posortowane pod względem objawów
        a) Każdy węzeł to:
            - Nazwa objawu
            - Drzewo dla objawu posortowane względem zawodów, gdzie każdy węzeł to:
                * Nazwa zawodu
                * Ilość chłopów danego zawodu z objawe
*/

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
        return root;
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
        cout << currentNode->key << "(" << *currentNode->value << ") ";
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

    SplayTree operator+(const SplayTree& treeToAdd) {
        // This will add the root of the second tree to the first
        this->insert(treeToAdd.root->key, treeToAdd.root->value);
        return *this;
    }
};

int main() {

    SplayTree<SplayTree<int>>* professionParentTree = new SplayTree<SplayTree<int>>();
    SplayTree<SplayTree<int>>* symptomParentTree = new SplayTree<SplayTree<int>>();

    
    string prof = "rolnik";
    string symptom = "zle_calkowanie";
    SplayTree<int>* symptomInternalTree = new SplayTree<int>();
    symptomInternalTree->insert(symptom, new int(1));
    professionParentTree->insert(prof, symptomInternalTree);
    professionParentTree->insert(prof, symptomInternalTree);

    symptom = "zle_rozniczkowanie";
    // delete symptomInternalTree;
    symptomInternalTree = new SplayTree<int>();
    symptomInternalTree->insert(symptom, new int(1));
    professionParentTree->insert(prof, symptomInternalTree);

    professionParentTree->find(prof)->printTree();



    // THE TASK:
    /*
    unsigned int numberOfOperations;
    for (int i=0; i<numberOfOperations; i++) {
        char operation;
        cin >> operation;
        fflush(stdin);
        if (operation == 'd') {
            string profession, symptom;
            cin >> profession >> symptom;
            // Add peasant to database

        } else if (operation == 's') {
            string symptom;
            cin >> symptom;
            // Write peasants of symptoms
        } else if (operation == 'p') {
            string profession;
            cin >> profession;
            // Write peasants of professions
        }
    }
    */

    return 0;
}
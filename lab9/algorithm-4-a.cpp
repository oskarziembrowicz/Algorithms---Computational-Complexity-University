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
            }
            // Here do the second rotation
            if (root->left) {
                return rotateRight(root);
            } else {
                return root;
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
            }
            if (root->right) {
                return rotateLeft(root);
            } else {
                return root;
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

    // Node* find(Node* root, string key) {
    //     return splay(root, key);
    // }

    void printTree(Node* currentNode) {
        if (!currentNode) {
            return;
        }
        printTree(currentNode->left);
        cout << currentNode->key << "(" << *currentNode->value << ") ";
        printTree(currentNode->right);
    }

    void printKeys(Node* currentNode) {
        if (!currentNode) {
            return;
        }
        printKeys(currentNode->left);
        cout << currentNode->key << " ";
        printKeys(currentNode->right);
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
        root = splay(root, key);
        // return root->value;
        return root->key == key ? root->value : NULL;
    }

    void printTree() {
        printTree(root);
    }

    void printKeys() {
        printKeys(root);
    }

    SplayTree operator+(const SplayTree& treeToAdd) {
        // This will add the root of the second tree to the first
        this->insert(treeToAdd.root->key, treeToAdd.root->value);
        return *this;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    SplayTree<SplayTree<int>>* professionExternalTree = new SplayTree<SplayTree<int>>();
    SplayTree<SplayTree<int>>* symptomExternalTree = new SplayTree<SplayTree<int>>();
    SplayTree<int>* result = new SplayTree<int>();

    /*
    string prof = "rolnik";
    string symptom = "zle_calkowanie";
    SplayTree<int>* symptomInternalTree = new SplayTree<int>();
    symptomInternalTree->insert(symptom, new int(1));
    professionExternalTree->insert(prof, symptomInternalTree);
    professionExternalTree->insert(prof, symptomInternalTree);

    symptom = "zle_rozniczkowanie";
    // delete symptomInternalTree;
    symptomInternalTree = new SplayTree<int>();
    symptomInternalTree->insert(symptom, new int(1));
    professionExternalTree->insert(prof, symptomInternalTree);

    professionExternalTree->find(prof)->printTree();
    */



    // THE TASK:
    unsigned int numberOfOperations;
    cin >> numberOfOperations;

    for (int i=0; i<numberOfOperations; i++) {
        char operation;
        cin >> operation;
        if (operation == 'd') {
            string profession, symptom;
            cin >> profession >> symptom;


            // Add peasant to database
            SplayTree<int>* symptomInternalTree = new SplayTree<int>();
            symptomInternalTree->insert(symptom, new int(1));
            professionExternalTree->insert(profession, symptomInternalTree);
            // JUST FOR TESTING
            // cout << "Drzewo zawodow: ";
            // professionExternalTree->find(profession)->printTree();
            // cout << ", ";
            // professionExternalTree->printKeys();
            // cout << "\n";

            SplayTree<int>* professionInternalTree = new SplayTree<int>();
            professionInternalTree->insert(profession, new int(1));
            symptomExternalTree->insert(symptom, professionInternalTree);
            // JUST FOR TESTING
            // cout << "Drzewo symptomow: ";
            // symptomExternalTree->find(symptom)->printTree();
            // cout << ", ";
            // symptomExternalTree->printKeys();
            // cout << "\n";

        } else if (operation == 's') {
            string symptom;
            cin >> symptom;
            // Print peasants of symptoms
            result = symptomExternalTree->find(symptom);
            if (result) {
                result->printTree();
                cout << "\n";
            }
        } else if (operation == 'p') {
            string profession;
            cin >> profession;
            // Print peasants of professions
            result = professionExternalTree->find(profession);
            if (result) {
                result->printTree();
                cout << "\n";
            }
        }
    }

    // professionExternalTree->find("rolnik")->printTree();
    // cout << "\n";

    return 0;
}
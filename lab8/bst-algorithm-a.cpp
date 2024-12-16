#include <iostream>

using namespace std;

struct Peasant {
    string profession;
    string symptom;
};

template <typename T> class BST {
    struct Node {
        T value;
        Node* left;
        Node* right;
    };
public:
    BST() {
        treeSize = 0;
        root = NULL;
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

struct ProfessionNode {
    string profession;
    int numberOfPeasants;
};

struct SymptomNode {
    string symptom;
    int numberOfPeasants;
    BST<ProfessionNode> ProfessionsInsideTree;
};

// drzewa BST
// insert()
// find()
// Print all

// Use tamplates
// Thee - the node is another tree
// Tree of symptoms (with a sum of peasants) and for each symptom a tree of professions (with sum of peasants)
// Make two trees like that

int main() {
    int numberOfData;
    cin >> numberOfData;

    for (int i=0; i<numberOfData; i++) {
        char flag;
        cin >> flag;
        if (flag == 'd') {
            string profession, symptom;
            cin >> profession >> symptom;
            // add a peasant to data base with profession and symptoms
        } else if (flag == 's') {
            string symptom;
            cin >> symptom;
            // print number of peasants for each profession of given syptoms (sorted by profession)
        } else if (flag == 'p') {
            string profession;
            cin >> profession;
            // print number of peasants for each symptom of given profession (sorted by symptom)
        }
    }

    return 0;
}
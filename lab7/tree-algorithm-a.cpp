#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int min;
    int max;
    Node() {}
    Node(int min, int max) {
        this->min = min;
        this->max = max;
    }
};

Node DUMMY_NODE = Node(INT_MAX, 0);

void printTree(Node* tree, int size) {
    for (int i=0; i<size; i++) {
        int min = tree[i].min;
        int max = tree[i].max;
        if (min == INT_MAX) {
            min = -1;
            max = -1;
        }
        cout << "(" << min << ", " << max << ") ";
    }
    cout << "\n";
}

Node compareNodes(Node n1, Node n2) {
    return Node(min(n1.min, n2.min), max(n1.max, n2.max));
}

void buildTree(Node* tree, Node value, int nodeIndex, int start, int end) {
    if (start == end) {
        tree[nodeIndex] = value;
    } else {
        int middle = (start + end) / 2;
        // Left branch
        buildTree(tree, value, nodeIndex*2, start, middle);
        // Right branch
        buildTree(tree, value, nodeIndex*2+1, middle+1, end);
        tree[nodeIndex] = value;
    }
}

void update(Node* tree, int nodeIndex, int start, int end, int targetIndex, Node value) {
    if (start == end) {
        tree[nodeIndex] = value;
    } else {
        int middle = (start + end)/2;
        if (targetIndex <= middle) {
            update(tree, nodeIndex*2, start, middle, targetIndex, value);
        } else {
            update(tree, nodeIndex*2+1, middle+1, end, targetIndex, value);
        }
        tree[nodeIndex] = compareNodes(tree[nodeIndex*2], tree[nodeIndex*2+1]);
    }
}

Node getRating(Node* tree, int nodeIndex, int start, int end, int queryStart, int queryEnd) {
    if (queryStart > queryEnd) {
        return DUMMY_NODE;
    }
    if (start == queryStart && end == queryEnd) {
        return tree[nodeIndex];
    }
    int middle = (start+end)/2;
    Node leftNode = getRating(tree, nodeIndex*2, start, middle, queryStart, min(queryEnd, middle));
    Node rightNode = getRating(tree, nodeIndex*2+1, middle+1, end, max(queryStart, middle+1), queryEnd);
    return compareNodes(leftNode, rightNode);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int numberOfQuerys, numberOfPeasants;
    cin >> numberOfQuerys >> numberOfPeasants;

    // Initialize an empty tree
    int treeSize = numberOfPeasants*4;
    Node* tree = new Node[treeSize];
    for (int i=0; i<treeSize; i++) {
        tree[i] = DUMMY_NODE;
    }

    // Build the tree
    Node zeroNode;
    zeroNode.min = 0;
    zeroNode.max = 0;
    buildTree(tree, zeroNode, 1, 0, numberOfPeasants-1); // first node 1, because 0*2 is 0

    // Querys
    for (int i=0; i<numberOfQuerys; i++) {
        int flag, v1, v2;
        cin >> flag >> v1 >> v2;

        if (flag) {
            // Get ratings in range
            Node result = getRating(tree, 1, 0, numberOfPeasants-1, v1, v2);
            cout << result.min << " " << result.max << "\n";
        } else {
            // Update tree (rate a peasant)
            update(tree, 1, 0, numberOfPeasants-1, v1, Node(v2, v2));
        }
    }

    delete[] tree;

    return 0;
}
#include <iostream> 
#include <algorithm>
#include <string> 
#include <vector>

using namespace std;

struct Node {
    int value;

    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};


Node* createNode(int value) {
    Node* newNode = new Node(value);
    return newNode;
}

void inOrder(Node* head) {
    if (!head) {
        return;
    }

    inOrder(head->left);

    cout << head->value << endl;

    inOrder(head->right);
}


void postOrder(Node* head) {
    if (!head) {
        return;
    }

    postOrder(head->left);
    postOrder(head->right);

    cout << head->value << endl;
}

void preOrder(Node* head) {
    if (!head) {
        return;
    }

    cout << head->value << endl;

    preOrder(head->left);
    preOrder(head->right);
}



int main() {
    Node* first = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* four = createNode(4);
    Node* five = createNode(5);
    Node* six = createNode(6);
    Node* seven = createNode(7);
    Node* eight = createNode(8);

    // Degenerate Tree (Linked List)
    first->right = second;
    second->right = third;
    third->right = four;
    four->right = five;
    five->right = six;
    six->right = seven;
    seven->right = eight;


    for (Node* i = first; i != nullptr; i = i -> right) {
        cout << i->value << endl;
    }

    cout << "Post-Order traversal of a BST tree: " << endl;
    preOrder(first);

    cout << "In-Order traversal of a BST tree: " << endl;
    inOrder(first); 

    cout << "Post-Order traversal of a BST tree: " << endl;
    postOrder(first);
}


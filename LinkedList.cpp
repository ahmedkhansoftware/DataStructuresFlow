#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;

    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

Node* reverseList(Node* head) {
    Node* current = head;
    Node* next = head;

    Node* previous = nullptr;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}


Node* createNode(int value) {
    Node* newNode = new Node(value);
    return newNode;
}

int lengthOfLinkedList(Node* head) {
    if (!head) return 0;

    int count = 0;

    for (Node* i = head; i != nullptr; i = i -> next) {
        count++;
    }

    return count;
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
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;

    cout << "Traversing a Linked List: " << endl;

    for (Node* i = first; i != nullptr; i = i -> next) {
        cout << i->value << endl;
    }

    cout << "Reversing a Linked List: " << endl;

    first = reverseList(first);

    for (Node* i = first; i != nullptr; i = i -> next) {
        cout << i->value << endl;
    }

    cout << "Find the middle of a Linked List: " << endl;

    int length = lengthOfLinkedList(first);

    for (int i = 0; i < length / 2; i++) {
        first = first->next;
    }

    cout << first->value << endl;
}



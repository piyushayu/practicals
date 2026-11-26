#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    explicit Node(int val) : data(val), next(nullptr) {}
};

void appendNode(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of nodes cannot be negative.\n";
        return 1;
    }

    if (n > 0) {
        cout << "Enter " << n << " values: ";
        for (int i = 0; i < n; ++i) {
            cin >> val;
            appendNode(head, tail, val);
        }
    }

    cout << "Linked List: ";
    printList(head);
    cout << "Total number of nodes: " << countNodes(head) << "\n";

    freeList(head);
    return 0;
}

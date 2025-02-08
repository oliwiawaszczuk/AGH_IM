#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} // Konstruktor
};

void insertSorted(Node*& head, int val, bool ascending) {
    Node* newNode = new Node(val);
    if (!head || (ascending && head->data >= val) || (!ascending && head->data <= val)) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next &&
           ((ascending && temp->next->data < val) || (!ascending && temp->next->data > val))) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;
    Node* even_head = nullptr, *odd_head = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            insertSorted(even_head, val, true);
        } else {
            insertSorted(odd_head, val, false);
        }
    }


    printList(even_head);
    printList(odd_head);

    return 0;
}

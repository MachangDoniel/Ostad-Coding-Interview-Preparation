#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* partitionList(Node* head, int X) {
    Node beforeHead(0), afterHead(0);
    Node *before = &beforeHead, *after = &afterHead;
    
    while (head) {
        if (head->data < X) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    
    after->next = nullptr;
    before->next = afterHead.next;
    
    return beforeHead.next;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int N, X;
    cin >> N;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    cin >> X;
    head = partitionList(head, X);
    printList(head);
    
    return 0;
}

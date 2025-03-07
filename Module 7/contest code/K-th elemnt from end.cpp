#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeKthFromEnd(Node* head, int K) {
    Node dummy(0);
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;
    
    for (int i = 0; i <= K; i++) {
        first = first->next;
    }
    
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    Node* toDelete = second->next;
    second->next = toDelete->next;
    delete toDelete;
    
    return dummy.next;
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
    int N, K;
    cin >> N >> K;
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
    
    head = removeKthFromEnd(head, K);
    printList(head);
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseSublist(Node* head, int L, int R) {
    if (!head || L == R) return head;
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    for (int i = 1; i < L; i++) prev = prev->next;
    Node* current = prev->next;
    Node* next = nullptr;
    for (int i = 0; i < R - L; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
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
    int N, L, R;
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
    
    cin >> L >> R;
    head = reverseSublist(head, L, R);
    printList(head);
    
    return 0;
}

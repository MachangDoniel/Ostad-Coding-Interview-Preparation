#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    // Node(int val) : data(val), next(nullptr) {}
    Node(int val){ 
        data=val;
        next=nullptr;
    }
};

void removeDuplicates(Node* head) {
    unordered_map<int,int> seen;
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (seen[current->data]) {
            prev->next = current->next;
            delete current;
        } else {
            seen[current->data]++;
            prev = current;
        }
        current = prev->next;
    }
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
    int N;
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
    
    removeDuplicates(head);
    printList(head);
    
    return 0;
}

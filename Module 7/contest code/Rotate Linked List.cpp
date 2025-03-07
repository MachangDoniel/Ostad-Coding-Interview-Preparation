#include <bits/stdc++.h>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to rotate the linked list counter-clockwise by K positions
Node* rotateList(Node* head, int K) {
    if (!head || K == 0) return head;
    
    // Find the length of the linked list
    Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }
    
    // If K is a multiple of length, no rotation is needed
    K = K % length;
    if (K == 0) return head;
    
    // Traverse to the (K)th node
    Node* newTail = head;
    for (int i = 1; i < K; i++) {
        newTail = newTail->next;
    }
    
    // New head is the next node
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    
    // Find the last node of the remaining list
    temp = newHead;
    while (temp->next) {
        temp = temp->next;
    }
    
    // Connect the last node to the old head
    temp->next = head;
    
    return newHead;
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
    
    head = rotateList(head, K);
    printList(head);
    
    return 0;
}
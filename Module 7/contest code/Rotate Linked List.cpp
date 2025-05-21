// Rotate Linked List

// You are given N integers and an integer K (1 ≤ K ≤ N). Create a singly linked list with the N integers sequentially. A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer. Now, suppose you don't have any information, you only have the head pointer of the linked list. You don't even know the size of the linked list. Your task is to rotate the linked list K times counter-clockwise.

// For example, if the given linked list is 1 -> 2 -> 3 -> 4 -> 5 and K is 3, then after rotating 1st time: 2 -> 3 -> 4 -> 5 -> 1, after rotating 2nd time: 3 -> 4 -> 5 -> 1 -> 2, after rotating 3rd time: 4 -> 5 -> 1 -> 2 -> 3.

// Input: First line of the input contains two integers N and K. Next line contains N space separated integers, the values of the linked list in order.

// Output: Print the elements of linked list after rotating K times counter-clockwise.

// Constraints: 1 ≤ N ≤ 10000, 1 ≤ K ≤ N. All the provided integers are in range \[1, 10000].

// Example 1:
// Input:
// 5 2
// 1 2 3 4 5
// Output:
// 3 4 5 1 2

// Example 2:
// Input:
// 5 5
// 1 2 3 4 5
// Output:
// 1 2 3 4 5

// Example 3:
// Input:
// 5 1
// 1 2 3 4 5
// Output:
// 2 3 4 5 1

// Note: This problem can be solved without using linked list. But you should solve this problem as guided for your own betterment.




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
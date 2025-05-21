// Reverse Linked List

// EN
// বাং
// Problem Statement
// You are given 
// N
// N integers. Create a singly linked list with these integers sequentially.

// A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer.
// Now, suppose you don't have any infomation, you only have the head pointer of the linked list. You don't even know the size of the linked list. Your task is reverse the linked list and print the values of the reversed linked list.

// For example, if the given linked list is 
// 1
// 1 -> 
// 2
// 2 -> 
// 3
// 3 -> 
// 4
// 4 -> 
// 5
// 5 then the after reversing the linked list should be 
// 5
// 5 -> 
// 4
// 4 -> 
// 3
// 3 -> 
// 2
// 2 -> 
// 1
// 1.

// Input
// First line of the input contains an integer 
// N
// N, number of integers.
// Next line contains 
// N
// N space separated integers, the values of the linked list in order.

// Output
// Print 
// N
// N integers, the values of the reversed linked list in order.

// Constraints
// 1
// 1 
// ≤
// ≤ 
// N
// N 
// ≤
// ≤ 
// 10000
// 10000
// All the provided integers are in range 
// [
// 1
// ,
// 1000
// ]
// [1,1000]
// Example 1:
// Input:
// 5
// 1 2 3 4 5
// Output:
// 5 4 3 2 1
// Example 2:
// Input:
// 3
// 1 7 3
// Output:
// 3 7 1
// Note:
// This problem can be solved without using linked list. But you should solve this problem as guided for your own betterment.



#include <bits/stdc++.h>
using namespace std;

// Define the structure of a linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to create a linked list from an array
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    Node* head = new Node(values[0]);
    Node* current = head;
    
    for (int i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    
    return head;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr != nullptr) {
        Node* nextNode = curr->next;  // Save next node
        curr->next = prev;            // Reverse the current node's pointer
        prev = curr;                  // Move prev and curr one step forward
        curr = nextNode;
    }
    
    return prev;  // The new head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    // Step 1: Create the linked list from input values
    Node* head = createLinkedList(values);
    
    // Step 2: Reverse the linked list
    head = reverseList(head);
    
    // Step 3: Print the reversed linked list
    printList(head);

    return 0;
}

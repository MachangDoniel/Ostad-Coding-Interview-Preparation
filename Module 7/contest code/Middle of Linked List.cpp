// Middle of Linked List
// Problem Statement
// You are given N integers. Create a singly linked list with these integers sequentially.

// A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer. Now, suppose you don't have any information, you only have the head pointer of the linked list. You don't even know the size of the linked list. Your task is to find the middle element of the linked list using only the limited information you have.

// For example, if the given linked list is 1 -> 2 -> 3 -> 4 -> 5 then the output should be 3.

// If there are even number of elements, then there would be two elements, we need to print the second middle element. If the given linked list is 1 -> 2 -> 3 -> 4 -> 5 -> 6 then the output should be 4.

// Input
// First line of the input contains an integer N, number of integers.
// Next line contains N space separated integers.

// Output
// Print an integer, the value of the middle element of the linked list.

// Constraints
// 1 ≤ N ≤ 1000
// All the provided integers are in range \[1,1000]

// Example 1:
// Input:
// 5
// 1 2 3 4 5
// Output:
// 3

// Example 2:
// Input:
// 6
// 1 6 2 5 9 1
// Output:
// 5

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

// Function to find the middle element of the linked list
int findMiddle(Node* head) {
    if (head == nullptr) return -1;  // Empty list case
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;        // Move slow by 1
        fast = fast->next->next;  // Move fast by 2
    }
    
    return slow->data;  // Slow will be at the middle when fast reaches the end
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
    
    // Step 2: Find the middle element and print it
    cout << findMiddle(head) << endl;

    return 0;
}

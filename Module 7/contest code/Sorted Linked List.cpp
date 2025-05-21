// Sorted Linked List
// Problem Statement
// You are given N integers. Create a singly linked list with these integers sequentially.

// A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer. Now, suppose you don't have any information, you only have the head pointer of the linked list. You don't even know the size of the linked list. Your task is to determine if the linked list is in non-decreasing order or not.

// A linked list is in non-decreasing order if the elements are greater than, or equal to the previous element. For example, if the given linked list is 1 -> 3 -> 3 -> 6 -> 7 then it's in non-decreasing order and 1 -> 4 -> 3 this linked list is not.

// Input
// First line of the input contains an integer N, number of integers.
// Next line contains N space separated integers, the values of the linked list in order.

// Output
// Print "YES" if the linked list is in non-decreasing order, "NO" otherwise.

// Constraints
// 1 ≤ N ≤ 10000
// All the provided integers are in range \[1,10000]

// Example 1:
// Input:
// 5
// 1 3 3 6 7
// Output:
// YES

// Example 2:
// Input:
// 3
// 1 7 3
// Output:
// NO

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

// Function to check if the linked list is in non-decreasing order
bool isSorted(Node* head) {
    if (!head || !head->next) return true;  // A list with one or no elements is sorted.
    
    Node* current = head;
    while (current->next) {
        if (current->data > current->next->data) {
            return false;  // If we find an element greater than the next, return false
        }
        current = current->next;
    }
    
    return true;  // If we traverse the list without finding violations, it's sorted
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
    
    // Step 2: Check if the list is sorted
    if (isSorted(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

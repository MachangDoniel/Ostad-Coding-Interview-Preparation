// Palindrome Linked List
// Problem Statement
// You are given N integers. Create a singly linked list with these integers sequentially.

// A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer. Now, suppose you don't have any information, you only have the head pointer of the linked list. You don't even know the size of the linked list. Your task is to determine if the linked list is palindrome or not.

// A palindrome linked list is a linked list that stays the same when reversed. For example, if the given linked list is 1 -> 2 -> 3 -> 2 -> 1 then it's a palindrome and 1 -> 2 this linked list is not.

// Input
// First line of the input contains an integer N, number of integers.
// Next line contains N space separated integers, the values of the linked list in order.

// Output
// Print "YES" if the linked list is palindrome, "NO" otherwise.

// Constraints
// 1 ≤ N ≤ 10000
// All the provided integers are in range \[1,1000]

// Example 1:
// Input:
// 5
// 1 2 3 4 5
// Output:
// NO

// Example 2:
// Input:
// 5
// 1 7 3 7 1
// Output:
// YES

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

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
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

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;  // Empty or single node list is a palindrome
    
    // Step 1: Find the middle of the linked list
    Node* middle = findMiddle(head);
    
    // Step 2: Reverse the second half of the list
    Node* secondHalf = reverseList(middle);
    
    // Step 3: Compare the first half and the reversed second half
    Node* firstHalf = head;
    Node* secondHalfCopy = secondHalf;  // For restoration purpose
    
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;  // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    // Optional: Reverse the second half back to its original state
    reverseList(secondHalfCopy);  // Restore the list if needed
    
    return true;  // The list is a palindrome
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
    
    // Step 2: Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

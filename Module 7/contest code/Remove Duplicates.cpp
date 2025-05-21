// **Remove Duplicates**

// **Problem Statement**
// You are given **N** integers. Create a singly linked list with the **N** integers sequentially.

// A singly linked list is a linear data structure in which elements are not stored in contiguous memory locations, and each element points to the next element.

// You only have the head pointer of the linked list and do not know the size of the linked list. Your task is to remove duplicate elements from the linked list. For every type of element, keep the first occurrence and delete the rest.

// For example, if the linked list is:
// `1 -> 2 -> 1 -> 3 -> 2`
// The resulting linked list after removing duplicates will be:
// `1 -> 2 -> 3`

// ---

// **Input**

// * The first line contains one integer **N**.
// * The second line contains **N** space-separated integers, representing the linked list values in order.

// **Output**
// Print the elements of the linked list after removing duplicates.

// ---

// **Constraints**

// * 1 ≤ N ≤ 10,000
// * All integers are in the range \[1, 10,000]

// ---

// **Example 1**
// Input:

// ```
// 5
// 1 2 1 3 2
// ```

// Output:

// ```
// 1 2 3
// ```

// **Example 2**
// Input:

// ```
// 5
// 1 2 3 4 5
// ```

// Output:

// ```
// 1 2 3 4 5
// ```

// **Example 3**
// Input:

// ```
// 5
// 1 1 1 1 1
// ```

// Output:

// ```
// 1
// ```

// ---

// **Note:**
// This problem can be solved without using a linked list, but try solving it using linked list concepts for better understanding.



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

// **K-th Element from End**

// **Problem Statement**
// You are given **N** integers and an integer **K** (1 ≤ K ≤ N). Create a singly linked list with the **N** integers sequentially.

// A singly linked list is a linear data structure where elements are not stored in contiguous memory locations, and each element is connected only to its next element using a pointer.

// You only have the head pointer of the linked list and do not know the size of the linked list. Your task is to **delete the K-th element from the end** of the linked list.

// For example, if the linked list is:
// `1 -> 2 -> 3 -> 4 -> 5`
// and **K = 2**, after deletion the linked list will be:
// `1 -> 2 -> 3 -> 5`

// ---

// **Input**

// * The first line contains two integers **N** and **K**.
// * The second line contains **N** space-separated integers, representing the linked list values in order.

// **Output**
// Print the elements of the linked list after deleting the **K**-th element from the end.

// ---

// **Constraints**

// * 1 ≤ N ≤ 10,000
// * 1 ≤ K ≤ N
// * All integers are in the range \[1, 10,000]

// ---

// **Example 1**
// Input:

// ```
// 5 2
// 1 2 3 4 5
// ```

// Output:

// ```
// 1 2 3 5
// ```

// **Example 2**
// Input:

// ```
// 5 5
// 1 2 3 4 5
// ```

// Output:

// ```
// 2 3 4 5
// ```

// **Example 3**
// Input:

// ```
// 5 1
// 1 2 3 4 5
// ```

// Output:

// ```
// 1 2 3 4
// ```

// ---

// **Note:**
// This problem can be solved without using a linked list, but it is recommended to solve it using linked list concepts for better understanding.



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

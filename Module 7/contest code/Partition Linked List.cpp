// **Partition Linked List**

// **Problem Statement**
// You are given **N** integers and an integer **X**. Create a singly linked list with the **N** integers sequentially.

// A singly linked list is a linear data structure where elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer.

// You only have the head pointer of the linked list and do not know the size of the linked list. Your task is to **partition the linked list** such that all nodes with values **less than X** come first, then all nodes with values **greater than or equal to X** come after. The **original relative order** of the nodes in each partition should be preserved.

// For example, if the linked list is:
// `5 -> 4 -> 3 -> 2 -> 1`
// and **X = 3**, the resulting linked list should be:
// `2 -> 1 -> 5 -> 4 -> 3`

// ---

// **Input**

// * First line contains one integer **N**.
// * Second line contains **N** space-separated integers — the linked list values in order.
// * Third line contains one integer **X**.

// **Output**
// Print the elements of the linked list after partitioning.

// ---

// **Constraints**

// * 1 ≤ N ≤ 10,000
// * All integers are in the range \[1, 10,000]

// ---

// **Example 1**
// Input:

// ```
// 5
// 5 4 3 2 1
// 3
// ```

// Output:

// ```
// 2 1 5 4 3
// ```

// **Example 2**
// Input:

// ```
// 5
// 1 2 3 4 5
// 3
// ```

// Output:

// ```
// 1 2 3 4 5
// ```

// **Example 3**
// Input:

// ```
// 3
// 3 2 1
// 5
// ```

// Output:

// ```
// 3 2 1
// ```

// ---

// **Note:**
// This problem can be solved without using linked lists, but it is recommended to solve it using linked list concepts for better understanding.



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* partitionList(Node* head, int X) {
    Node beforeHead(0), afterHead(0);
    Node *before = &beforeHead, *after = &afterHead;
    
    while (head) {
        if (head->data < X) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    
    after->next = nullptr;
    before->next = afterHead.next;
    
    return beforeHead.next;
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
    int N, X;
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
    
    cin >> X;
    head = partitionList(head, X);
    printList(head);
    
    return 0;
}

// **Sublist Reverse**

// **Problem Statement**
// You are given **N** integers and two integers **L** and **R**. Create a singly linked list with the **N** integers sequentially.

// A singly linked list is a linear data structure in which elements are not stored in contiguous memory locations, and each element points only to the next element using a pointer.

// You only have the head pointer of the linked list and do not know the size of the linked list. Your task is to reverse the sublist from the **L**th node to the **R**th node.

// For example, if the linked list is:
// `1 -> 5 -> 6 -> 8 -> 3`
// and **L = 2**, **R = 4**, the resulting linked list after reversing the sublist will be:
// `1 -> 8 -> 6 -> 5 -> 3`

// ---

// **Input**

// * The first line contains one integer **N**.
// * The second line contains **N** space-separated integers, representing the linked list values in order.
// * The third line contains two integers **L** and **R**.

// **Output**
// Print the elements of the linked list after reversing the sublist.

// ---

// **Constraints**

// * 1 ≤ N ≤ 10,000
// * 1 ≤ L < R ≤ N
// * All integers are in the range \[1, 10,000]

// ---

// **Example 1**
// Input:

// ```
// 5
// 1 5 8 6 3
// 2 4
// ```

// Output:

// ```
// 1 6 8 5 3
// ```

// **Example 2**
// Input:

// ```
// 5
// 1 2 3 4 5
// 1 3
// ```

// Output:

// ```
// 3 2 1 4 5
// ```

// **Example 3**
// Input:

// ```
// 5
// 1 2 3 4 5
// 3 5
// ```

// Output:

// ```
// 1 2 5 4 3
// ```

// **Example 4**
// Input:

// ```
// 5
// 1 2 3 4 5
// 1 5
// ```

// Output:

// ```
// 5 4 3 2 1
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

Node* reverseSublist(Node* head, int L, int R) {
    if (!head || L == R) return head;
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    for (int i = 1; i < L; i++) prev = prev->next;
    Node* current = prev->next;
    Node* next = nullptr;
    for (int i = 0; i < R - L; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
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
    int N, L, R;
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
    
    cin >> L >> R;
    head = reverseSublist(head, L, R);
    printList(head);
    
    return 0;
}

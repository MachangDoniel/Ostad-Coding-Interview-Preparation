// **Linked List Summation**

// **Problem Statement**
// You are given 2 large integers. Create two singly linked lists with the digits of the integers sequentially.

// A singly linked list is a linear data structure where elements are not stored in contiguous memory locations, and each element is connected only to its next element using a pointer.

// You only have the head pointer of the linked lists and do not know the size of the linked list. Your task is to add the integers using linked lists and create a new linked list that stores the summation.

// For example, given the numbers:
// `4786` and `5849`,
// the two linked lists are:
// `4 -> 7 -> 8 -> 6` and
// `5 -> 8 -> 4 -> 9`.

// Adding them using linked lists results in the linked list:
// `1 -> 0 -> 6 -> 3 -> 5` (which represents 10635). The output is:
// `ostad10635`.

// ---

// **Input**

// * Two lines, each containing a large integer as a string.

// **Output**

// * Print the word `"ostad"` followed immediately by the summation of the two integers (no spaces).

// ---

// **Constraints**

// * Each integer can be up to 10,000 digits long.

// ---

// **Example 1**
// Input:

// ```
// 4786
// 5849
// ```

// Output:

// ```
// ostad10635
// ```

// **Example 2**
// Input:

// ```
// 12
// 9999
// ```

// Output:

// ```
// ostad10011
// ```

// **Example 3**
// Input:

// ```
// 5555
// 1
// ```

// Output:

// ```
// ostad5556
// ```

// ---

// **Note:**
// This problem can be solved without using linked lists, but it is encouraged to solve it using linked list concepts for better learning.



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addLists(Node* l1, Node* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1->data);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->data);
        l2 = l2->next;
    }
    
    Node* result = nullptr;
    int carry = 0;
    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }
        
        Node* newNode = new Node(sum % 10);
        newNode->next = result;
        result = newNode;
        carry = sum / 10;
    }
    return result;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* createList(string num) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (char c : num) {
        Node* newNode = new Node(c - '0');
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    Node* l1 = createList(num1);
    Node* l2 = createList(num2);
    
    Node* result = addLists(l1, l2);
    
    cout << "ostad";
    printList(result);
    
    return 0;
}

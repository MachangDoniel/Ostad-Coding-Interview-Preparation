/*
Given an integer n, construct 2 function.

Your first function returns the digit representation of the number as a doubly linked list(sign <->).

Your second function returns the integer extracted from the linked list representation.

Constraints:

-2^31 <= n <= 2^31 - 1

Example 1:

Input: n = 25

Output: first function: 2 <-> 5

	  second function: 25

Example 2:

Input: n = -4

Output: first function: - <-> 4

	  second function: -4
*/

#include<bits/stdc++.h>

using namespace std;

// Doubly Linked List Node
struct ListNode {
    char val;
    ListNode* prev;
    ListNode* next;
    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

// Convert integer to doubly linked list
ListNode* intToLinkedList(int n) {
    string num = to_string(n);
    ListNode* head = new ListNode(num[0]);
    ListNode* curr = head;
    for (int i = 1; i < num.size(); i++) {
        ListNode* newNode = new ListNode(num[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

// Convert doubly linked list to integer
int linkedListToInt(ListNode* head) {
    string num = "";
    while (head) {
        num += head->val;
        head = head->next;
    }
    return stoi(num);
}


int main() {
    // Example
    // int num = -4;
    int num = -1234;
    ListNode* head = intToLinkedList(num);
    cout << "Linked List Representation: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "Converted Back: " << linkedListToInt(head) << endl;

    return 0;
}

/*
You are given the elements(integer) of an array and the elements(integer) of a linked list. 
Construct the linked list and array, then Return the head of the modified linked list after 
removing all nodes from the linked list that have a value that exists in the array and print it.


Example 1:

input: array= [1,2,3], linked list= [1,2,3,4,5]  

Output: [4,5]

Example 2:

	input: array= [5], linked list= [1,2,3,4]  

Output: [1,2,3,4]
*/

#include<bits/stdc++.h>

using namespace std;


// Delete elements from linked list that exist in array
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* removeElements(Node* head, unordered_set<int>& values) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy, *curr = head;
    while (curr) {
        if (values.count(curr->val)) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example
    int arr[] = {1, 2, 3};
    unordered_set<int> values(arr, arr + 3);
    Node* llist = new Node(1);
    llist->next = new Node(2);
    llist->next->next = new Node(3);
    llist->next->next->next = new Node(4);
    llist->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(llist);
    llist = removeElements(llist, values);
    cout << "Modified List: ";
    printList(llist);

    return 0;
}

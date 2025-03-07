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

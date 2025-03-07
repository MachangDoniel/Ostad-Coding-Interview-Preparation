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

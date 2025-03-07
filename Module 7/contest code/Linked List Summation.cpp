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

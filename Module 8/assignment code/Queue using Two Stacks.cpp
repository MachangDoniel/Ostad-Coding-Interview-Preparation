#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;  // Queue is empty
        int front = s2.top();
        s2.pop();
        return front;
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.empty() ? -1 : s2.top();
    }
    void print(){
        stack<int>st1=s1,st2=s2;
        cout<<"s1: ";
        while(!st1.empty()){
            cout<<st1.top()<<" ";
            st1.pop();
        }
        cout<<endl;
        cout<<"s2: ";
        while(!st2.empty()){
            cout<<st2.top()<<" ";
            st2.pop();
        }
        cout<<endl;
    }
};

int main() {
    int q;
    cin >> q;
    Queue qobj;
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            qobj.enqueue(x);
        } else if (type == 2) {
            cout << qobj.dequeue() << endl;
        } else if (type == 3) {
            cout << qobj.front() << endl;
        }
        qobj.print();
    }
    return 0;
}

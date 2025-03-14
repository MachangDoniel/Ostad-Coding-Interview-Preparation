#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);  // Initialize with -1
    stack<int> st;  // Monotonic stack (stores elements in decreasing order)

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();  // Remove larger elements
        }
        if (!st.empty()) {
            res[i] = st.top();  // Next smaller element
        }
        st.push(arr[i]);  // Push current element into stack
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = nextSmallerElement(arr);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}

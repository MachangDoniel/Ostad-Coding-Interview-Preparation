#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_max_length_subarray(int N, vector<int>& arr) {
    int max_length = 0;
    int current_length = 0;
    
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            current_length++;
            max_length = max(max_length, current_length);
        } else {
            current_length = 0;
        }
    }
    
    return max_length;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << find_max_length_subarray(N, arr) << endl;
    
    return 0;
}

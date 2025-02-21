#include <iostream>
#include <vector>
using namespace std;

void rotate_array(int N, int K, vector<int>& arr) {
    if (K == 0) {
        // Rotate right by one position
        int last = arr[N - 1];
        for (int i = N - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    } else if (K == 1) {
        // Rotate left by one position
        int first = arr[0];
        for (int i = 0; i < N - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[N - 1] = first;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    rotate_array(N, K, arr);
    
    // Output the rotated array
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

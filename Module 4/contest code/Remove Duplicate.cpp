#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Remove duplicates using a loop (since the array is sorted)
    vector<int> uniqueArr;
    uniqueArr.push_back(arr[0]); // First element is always unique

    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[i - 1]) { // Compare with the previous element
            uniqueArr.push_back(arr[i]);
        }
    }

    // Print the unique elements
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

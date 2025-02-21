#include <bits/stdc++.h>

using namespace std;

// Function to calculate the maximum gap between the elements in the sorted array
int maximumGap(vector<int>& nums) {
    // If the array has fewer than 2 elements, no gap can be calculated
    if (nums.size() < 2) return 0;

    int n = nums.size(); // Size of the input array
    int minValue = *min_element(nums.begin(), nums.end()); // Minimum value in the array
    int maxValue = *max_element(nums.begin(), nums.end()); // Maximum value in the array

    // If all elements are the same, the gap is 0
    if (minValue == maxValue) return 0;

    // Calculate the size of each bucket
    int bucketSize = max(1, (maxValue - minValue) / (n - 1));
    // Calculate the number of buckets needed
    int bucketCount = (maxValue - minValue) / bucketSize + 1;

    // Vectors to store the minimum and maximum values for each bucket, initialized to extreme values
    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    // Vector to track whether a bucket has been used or not
    vector<bool> bucketUsed(bucketCount, false);

    // Place each number in its corresponding bucket
    for (int num : nums) {
        // Calculate the index of the bucket where this number should go
        int bucketIndex = (num - minValue) / bucketSize;
        // Update the min and max values for this bucket
        bucketMin[bucketIndex] = min(bucketMin[bucketIndex], num);
        bucketMax[bucketIndex] = max(bucketMax[bucketIndex], num);
        // Mark the bucket as used
        bucketUsed[bucketIndex] = true;
    }

    // Initialize the previous bucket's maximum value to the minimum value of the input array
    int prevMax = minValue;
    int maxGap = 0; // To store the maximum gap between the elements

    // Iterate through each bucket to calculate the maximum gap
    for (int i = 0; i < bucketCount; i++) {
        // Skip empty buckets
        if (!bucketUsed[i]) continue;
        // Update the maximum gap found so far
        maxGap = max(maxGap, bucketMin[i] - prevMax);
        // Update the previous maximum value to the current bucket's maximum value
        prevMax = bucketMax[i];
    }

    return maxGap; // Return the maximum gap
}

int main() {
    // Example input
    vector<int> nums = {3, 6, 9, 1};
    // Call the function and print the result
    cout << maximumGap(nums) << endl; // Output: 3

    return 0;
}

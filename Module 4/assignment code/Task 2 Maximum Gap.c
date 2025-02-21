#include <stdio.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minValue = nums[0], maxValue = nums[0];
    // Find the minimum and maximum values in the array
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minValue) minValue = nums[i];
        if (nums[i] > maxValue) maxValue = nums[i];
    }

    // If all elements are the same, the gap is 0
    if (minValue == maxValue) return 0;

    // Calculate the size of each bucket
    int bucketSize = (maxValue - minValue) / (numsSize - 1);
    if (bucketSize == 0) bucketSize = 1; // Avoid zero-size bucket

    // Calculate the number of buckets needed
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    int bucketMin[bucketCount], bucketMax[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Arrays to track whether a bucket has been used or not
    int bucketUsed[bucketCount];
    for (int i = 0; i < bucketCount; i++) bucketUsed[i] = 0;

    // Place each number in its corresponding bucket
    for (int i = 0; i < numsSize; i++) {
        int bucketIndex = (nums[i] - minValue) / bucketSize;
        if (nums[i] < bucketMin[bucketIndex]) bucketMin[bucketIndex] = nums[i];
        if (nums[i] > bucketMax[bucketIndex]) bucketMax[bucketIndex] = nums[i];
        bucketUsed[bucketIndex] = 1;
    }

    int prevMax = minValue, maxGap = 0;

    // Iterate through each bucket to calculate the maximum gap
    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;
        maxGap = (bucketMin[i] - prevMax > maxGap) ? bucketMin[i] - prevMax : maxGap;
        prevMax = bucketMax[i];
    }

    return maxGap;
}

int main() {
    int nums[] = {3, 6, 9, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maximumGap(nums, numsSize)); // Output: 3

    return 0;
}

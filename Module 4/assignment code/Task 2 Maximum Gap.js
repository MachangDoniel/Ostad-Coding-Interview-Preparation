function maximumGap(nums) {
    // If the array has fewer than 2 elements, no gap can be calculated
    if (nums.length < 2) return 0;

    const n = nums.length;
    const minValue = Math.min(...nums); // Minimum value in the array
    const maxValue = Math.max(...nums); // Maximum value in the array

    // If all elements are the same, the gap is 0
    if (minValue === maxValue) return 0;

    // Calculate the size of each bucket
    const bucketSize = Math.max(1, Math.floor((maxValue - minValue) / (n - 1)));
    // Calculate the number of buckets needed
    const bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;

    // Arrays to store the minimum and maximum values for each bucket
    const bucketMin = new Array(bucketCount).fill(Infinity);
    const bucketMax = new Array(bucketCount).fill(-Infinity);
    // Array to track whether a bucket has been used or not
    const bucketUsed = new Array(bucketCount).fill(false);

    // Place each number in its corresponding bucket
    nums.forEach(num => {
        const bucketIndex = Math.floor((num - minValue) / bucketSize);
        bucketMin[bucketIndex] = Math.min(bucketMin[bucketIndex], num);
        bucketMax[bucketIndex] = Math.max(bucketMax[bucketIndex], num);
        bucketUsed[bucketIndex] = true;
    });

    let prevMax = minValue;
    let maxGap = 0;

    // Iterate through each bucket to calculate the maximum gap
    for (let i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;
        maxGap = Math.max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return maxGap;
}

// Example usage
const nums = [3, 6, 9, 1];
console.log(maximumGap(nums)); // Output: 3

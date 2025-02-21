using System;

class MaximumGap
{
    public static int MaximumGapFunc(int[] nums)
    {
        if (nums.Length < 2) return 0;

        int n = nums.Length;
        int minValue = int.MaxValue, maxValue = int.MinValue;

        // Find the minimum and maximum values in the array
        foreach (var num in nums)
        {
            minValue = Math.Min(minValue, num);
            maxValue = Math.Max(maxValue, num);
        }

        // If all elements are the same, the gap is 0
        if (minValue == maxValue) return 0;

        // Calculate the size of each bucket
        int bucketSize = Math.Max(1, (maxValue - minValue) / (n - 1));
        // Calculate the number of buckets needed
        int bucketCount = (maxValue - minValue) / bucketSize + 1;

        // Arrays to store the minimum and maximum values for each bucket
        int[] bucketMin = new int[bucketCount];
        int[] bucketMax = new int[bucketCount];
        for (int i = 0; i < bucketCount; i++)
        {
            bucketMin[i] = int.MaxValue;
            bucketMax[i] = int.MinValue;
        }

        // Array to track whether a bucket has been used or not
        bool[] bucketUsed = new bool[bucketCount];

        // Place each number in its corresponding bucket
        foreach (var num in nums)
        {
            int bucketIndex = (num - minValue) / bucketSize;
            bucketMin[bucketIndex] = Math.Min(bucketMin[bucketIndex], num);
            bucketMax[bucketIndex] = Math.Max(bucketMax[bucketIndex], num);
            bucketUsed[bucketIndex] = true;
        }

        int prevMax = minValue;
        int maxGap = 0;

        // Iterate through each bucket to calculate the maximum gap
        for (int i = 0; i < bucketCount; i++)
        {
            if (!bucketUsed[i]) continue;
            maxGap = Math.Max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }

    static void Main()
    {
        int[] nums = { 3, 6, 9, 1 };
        Console.WriteLine(MaximumGapFunc(nums)); // Output: 3
    }
}

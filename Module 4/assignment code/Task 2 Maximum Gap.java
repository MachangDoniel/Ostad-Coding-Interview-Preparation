import java.util.*;

public class MaximumGap {

    public static int maximumGap(int[] nums) {
        if (nums.length < 2) return 0;

        int n = nums.length;
        int minValue = Arrays.stream(nums).min().getAsInt(); // Minimum value in the array
        int maxValue = Arrays.stream(nums).max().getAsInt(); // Maximum value in the array

        // If all elements are the same, the gap is 0
        if (minValue == maxValue) return 0;

        // Calculate the size of each bucket
        int bucketSize = Math.max(1, (maxValue - minValue) / (n - 1));
        // Calculate the number of buckets needed
        int bucketCount = (maxValue - minValue) / bucketSize + 1;

        // Arrays to store the minimum and maximum values for each bucket
        int[] bucketMin = new int[bucketCount];
        int[] bucketMax = new int[bucketCount];
        Arrays.fill(bucketMin, Integer.MAX_VALUE);
        Arrays.fill(bucketMax, Integer.MIN_VALUE);
        // Array to track whether a bucket has been used or not
        boolean[] bucketUsed = new boolean[bucketCount];

        // Place each number in its corresponding bucket
        for (int num : nums) {
            int bucketIndex = (num - minValue) / bucketSize;
            bucketMin[bucketIndex] = Math.min(bucketMin[bucketIndex], num);
            bucketMax[bucketIndex] = Math.max(bucketMax[bucketIndex], num);
            bucketUsed[bucketIndex] = true;
        }

        int prevMax = minValue;
        int maxGap = 0;

        // Iterate through each bucket to calculate the maximum gap
        for (int i = 0; i < bucketCount; i++) {
            if (!bucketUsed[i]) continue;
            maxGap = Math.max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }

    public static void main(String[] args) {
        int[] nums = {3, 6, 9, 1};
        System.out.println(maximumGap(nums)); // Output: 3
    }
}

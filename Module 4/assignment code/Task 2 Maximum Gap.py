def maximum_gap(nums):
    # If the array has fewer than 2 elements, no gap can be calculated
    if len(nums) < 2:
        return 0

    n = len(nums)
    min_value = min(nums)  # Minimum value in the array
    max_value = max(nums)  # Maximum value in the array

    # If all elements are the same, the gap is 0
    if min_value == max_value:
        return 0

    # Calculate the size of each bucket
    bucket_size = max(1, (max_value - min_value) // (n - 1))
    # Calculate the number of buckets needed
    bucket_count = (max_value - min_value) // bucket_size + 1

    # Lists to store the minimum and maximum values for each bucket
    bucket_min = [float('inf')] * bucket_count
    bucket_max = [float('-inf')] * bucket_count
    # List to track whether a bucket has been used or not
    bucket_used = [False] * bucket_count

    # Place each number in its corresponding bucket
    for num in nums:
        bucket_index = (num - min_value) // bucket_size
        bucket_min[bucket_index] = min(bucket_min[bucket_index], num)
        bucket_max[bucket_index] = max(bucket_max[bucket_index], num)
        bucket_used[bucket_index] = True

    prev_max = min_value
    max_gap = 0

    # Iterate through each bucket to calculate the maximum gap
    for i in range(bucket_count):
        if not bucket_used[i]:
            continue
        max_gap = max(max_gap, bucket_min[i] - prev_max)
        prev_max = bucket_max[i]

    return max_gap


# Example usage
nums = [3, 6, 9, 1]
print(maximum_gap(nums))  # Output: 3

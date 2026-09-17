int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum is in the right half
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            // Minimum is in the left half, including mid
            right = mid;
        }
        else {
            // nums[mid] == nums[right]
            // Cannot determine which side contains the minimum
            right--;
        }
    }

    return nums[left];
}
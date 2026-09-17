long long mergeSort(int* nums, int* temp, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    long long count = 0;

    // Count reverse pairs in left and right halves
    count += mergeSort(nums, temp, left, mid);
    count += mergeSort(nums, temp, mid + 1, right);

    // Count cross reverse pairs
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right &&
               (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }

        count += j - (mid + 1);
    }

    // Normal merge
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int reversePairs(int* nums, int numsSize) {
    int* temp = (int*)malloc(numsSize * sizeof(int));

    long long count = mergeSort(nums, temp, 0, numsSize - 1);

    free(temp);

    return (int)count;
}
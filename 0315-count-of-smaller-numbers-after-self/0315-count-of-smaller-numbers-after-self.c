void merge(int* nums, int* indices, int* tempNums, int* tempIndices,
           int* count, int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (nums[indices[j]] < nums[indices[i]]) {
            // Right element is smaller
            tempIndices[k++] = indices[j++];
            rightCount++;
        }
        else {
            // All previously taken right elements are smaller
            count[indices[i]] += rightCount;
            tempIndices[k++] = indices[i++];
        }
    }

    while (i <= mid) {
        count[indices[i]] += rightCount;
        tempIndices[k++] = indices[i++];
    }

    while (j <= right) {
        tempIndices[k++] = indices[j++];
    }

    for (i = left; i <= right; i++) {
        indices[i] = tempIndices[i];
    }
}

void mergeSort(int* nums, int* indices, int* tempNums, int* tempIndices,
               int* count, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(nums, indices, tempNums, tempIndices,
              count, left, mid);

    mergeSort(nums, indices, tempNums, tempIndices,
              count, mid + 1, right);

    merge(nums, indices, tempNums, tempIndices,
          count, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {

    int* result = (int*)calloc(numsSize, sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));
    int* tempIndices = (int*)malloc(numsSize * sizeof(int));
    int* tempNums = NULL;

    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }

    mergeSort(nums, indices, tempNums, tempIndices,
              result, 0, numsSize - 1);

    free(indices);
    free(tempIndices);

    *returnSize = numsSize;
    return result;
}

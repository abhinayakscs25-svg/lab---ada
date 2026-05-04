/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int* arr, int low, int mid, int high) {
    int* b = (int*)malloc((high - low + 1) * sizeof(int));
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) {
            b[k] = arr[j];
            j++;
            k++;
        } else {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < high - low + 1; i++) {
        arr[low + i] = b[i];
    }
    free(b);
}

int mergesort(int* arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return 0;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergesort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}

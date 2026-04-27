#include <stdio.h>

void heapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] < heap[index]) {
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int n, int index) {
    int largest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;

            index = largest;
        } else {
            break;
        }
    }
}

void heapSort(int arr[], int n) {
    int heap[n];
    int size = 0;

    // Build heap (top-down)
    for (int i = 0; i < n; i++) {
        heap[size] = arr[i];
        heapifyUp(heap, size);
        size++;
    }

    // Extract elements
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(heap, size, 0);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

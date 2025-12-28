#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- MAX HEAP ---------- */
void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

/* ---------- MIN HEAP ---------- */
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void printHeap(int heap[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int maxHeap[] = {4, 10, 3, 5, 1};
    int minHeap[] = {4, 10, 3, 5, 1};
    int n = 5;
    int i;

    // Build Max Heap
    for (i = n/2 - 1; i >= 0; i--)
        maxHeapify(maxHeap, n, i);

    // Build Min Heap
    for (i = n/2 - 1; i >= 0; i--)
        minHeapify(minHeap, n, i);

    printf("Max Heap: ");
    printHeap(maxHeap, n);

    printf("Min Heap: ");
    printHeap(minHeap, n);

    return 0;
}

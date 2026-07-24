#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, k;
    printf("Enter the total number of frames (N) and the sliding window size (K): ");
    if (scanf("%d %d", &n, &k) != 2) return 1;
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the %d frame rendering times (space-separated): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *deque = (int *)malloc(n * sizeof(int));
    int front = 0;
    int rear = -1;
    printf("Maximum values for each window: ");
    for (int i = 0; i < n; i++) {
        while (front <= rear && deque[front] < i - k + 1) {
            front++;
        }
        while (front <= rear && arr[deque[rear]] <= arr[i]) {
            rear--;
        }
        rear++;
        deque[rear] = i;
        if (i >= k - 1) {
            printf("%d ", arr[deque[front]]);
        }
    }
    printf("\n");
    free(arr);
    free(deque);
    return 0;
}

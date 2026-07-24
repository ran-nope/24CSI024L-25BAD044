#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    
    int *arr = (int *)malloc(n * sizeof(int));
    int total_ones = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            total_ones++;
        }
    }

    if (total_ones <= 1) {
        printf("Min Swaps: 0\n");
        free(arr);
        return 0;
    }

    int current_ones = 0;
    int max_ones_in_window = 0;

    for (int i = 0; i < total_ones; i++) {
        if (arr[i] == 1) {
            current_ones++;
        }
    }
    max_ones_in_window = current_ones;

    for (int i = total_ones; i < n; i++) {
        if (arr[i] == 1) current_ones++;
        if (arr[i - total_ones] == 1) current_ones--;
        
        if (current_ones > max_ones_in_window) {
            max_ones_in_window = current_ones;
        }
    }

    printf("Min Swaps: %d\n", total_ones - max_ones_in_window);
    free(arr);
    return 0;
}

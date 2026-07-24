#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    
    int *arr = (int *)malloc(n * sizeof(int));
    int *res = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int left = 0;
    int right = n - 1;
    int index = n - 1;
    
    while (left <= right) {
        int l_val = abs(arr[left]);
        int r_val = abs(arr[right]);
        
        if (l_val > r_val) {
            res[index--] = l_val * l_val;
            left++;
        } else {
            res[index--] = r_val * r_val;
            right--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    free(arr);
    free(res);
    return 0;
}

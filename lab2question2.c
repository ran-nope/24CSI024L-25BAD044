#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    
    long long *arr = (long long *)malloc(n * sizeof(long long));
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        current_sum += arr[i];
        printf("%lld ", current_sum);
    }
    printf("\n");
    
    free(arr);
    return 0;
}

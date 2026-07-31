#include <stdio.h>
#include <limits.h>
int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int max = INT_MIN;
        int index = -1;
        for(int j = 0; j < n; j++) {
            if(a[j] > max) {
                max = a[j];
                index = j;
            }
        }
        if(i == k - 1)
            printf("\nThe %dth largest element is: %d", k, max);
        a[index] = INT_MIN;
    }
    return 0;
}

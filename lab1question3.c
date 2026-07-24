#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 100
 
typedef struct {
    int array[MAX_SIZE];
    int length;
} ListADT;
void initList(ListADT *list) {
    list->length = 0;
}
void insert(ListADT *list, int element) {
    if (list->length < MAX_SIZE) {
        list->array[list->length] = element;
        list->length++;
    } else {
        printf("List is full!\n");
    }
}
void display(ListADT *list) {
    printf("List: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}
 // Function to sort the list (Bubble Sort)
void sortList(ListADT *list) {
    for (int i = 0; i < list->length - 1; i++) {
        for (int j = 0; j < list->length - i - 1; j++) {
            if (list->array[j] > list->array[j + 1]) {
                // Swap the elements
                int temp = list->array[j];
                list->array[j] = list->array[j + 1];
                list->array[j + 1] = temp;
            }
        }
    }
}
// Binary Search Function
int binarySearch(ListADT *list, int target) {
    int low = 0;
    int high = list->length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (list->array[mid] == target) {
            return mid; // Target found
        }
        if (list->array[mid] < target) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }
    return -1; // Target not found
}
 
int main() {
    ListADT myList;
    initList(&myList);
    int n, value, target, index;
    printf("--- Assignment 3: Binary Search (Auto-Sorting) ---\n");   
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements in ANY order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&myList, value);
    }
    // Sort the list before searching
    sortList(&myList);
    printf("List has been sorted for Binary Search.\n");
    display(&myList);
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    index = binarySearch(&myList, target);
    if (index != -1) {
        printf("Result: Element %d found at index %d in the sorted list.\n", target, index);
    } else {
        printf("Result: Element %d not found in the list.\n", target);
    }
    return 0;
}

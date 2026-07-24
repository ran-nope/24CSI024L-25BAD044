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
// Linear Search Function
int linearSearch(ListADT *list, int target) {
    for (int i = 0; i < list->length; i++) {
        if (list->array[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}
int main() {
    ListADT myList;
    initList(&myList);
    int n, value, target, index; 
    printf("--- Assignment 2: Linear Search ---\n");   
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&myList, value);
    }
    display(&myList);
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    index = linearSearch(&myList, target);
    if (index != -1) {
        printf("Result: Element %d found at index %d.\n", target, index);
    } else {
        printf("Result: Element %d not found in the list.\n", target);
    }
    return 0;
}

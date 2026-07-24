#include<stdio.h>
#include<stdlib.h>
 
#define MAX_SIZE 100
 
typedef struct{
    int array[MAX_SIZE];
    int length;
}ListADT;
//Initialize List
void initList(ListADT *list){
    list->length=0;
}
//Insert Element
void insertAtEnd(ListADT *list,int element){
    if(list->length>=MAX_SIZE){
        printf("List is Full!\n");
        return;
    }
    list->array[list->length]=element;
    list->length++;
}
//Delete Element
void deleteAtIndex(ListADT *list,int index){
    if(list->length==0){
        printf("List is Empty!\n");
        return;
    }
    if(index<0||index>=list->length){
        printf("Invalid Index!\n");
        return;
    }
    for(int i=index;i<list->length-1;i++)
        list->array[i]=list->array[i+1];
    list->length--;
}
//Update Element
void updateAtIndex(ListADT *list,int index,int newValue){
    if(index<0||index>=list->length){
        printf("Invalid Index!\n");
        return;
    }
    list->array[index]=newValue;
}
//Display List
void display(ListADT *list){
    if(list->length==0){
        printf("List is Empty!\n");
        return;
    }
    for(int i=0;i<list->length;i++)
        printf("%d ",list->array[i]);
    printf("\n");
}
 
int main(){
    ListADT myList;
    initList(&myList);
    int choice,value,index;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Update\n4.Display\n5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
 
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&value);
                insertAtEnd(&myList,value);
                break; 
            case 2:
                printf("Enter Index: ");
                scanf("%d",&index);
                deleteAtIndex(&myList,index);
                break;
            case 3:
                printf("Enter Index: ");
                scanf("%d",&index);
                printf("Enter New Value: ");
                scanf("%d",&value);
                updateAtIndex(&myList,index,value);
                break;
            case 4:
                display(&myList);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

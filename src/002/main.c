#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
} *head;


void CreateNodeList(int n);
void displayList();
void displayReverseList();

void CreateNodeList(int n){

    head = (struct node*)malloc(sizeof(struct node));
    struct node* tail = head;
    int input = 0;
    for(int i = 0; i < n ; i++){
        struct node* tmp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &input);
        tmp->val = input;
        tmp->next  = NULL;
        tail->next = tmp;
        tail = tmp;
    }
}

void displayList(){
    struct node* tmp = head->next;
    while (tmp){
        printf("linklist data: %d\n", tmp->val);
        tmp = tmp->next;
    }
}


void displayReverseList(){
    
}

int main() {
    int n;
    printf("Linked List : To create and display Singly Linked List :\n");
    printf("-------------------------------------------------------------\n");

    printf("Input the number of nodes:");
    scanf("%d", &n);

    CreateNodeList(n);

    printf("\nDisplay data entered in the list:\n");

    displayList();
    displayReverseList();

    return  0;
}



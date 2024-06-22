#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Shape.h"
#include "Node.h"

void  strTrans(char *str){
    
    int i = 0;

    while (str[i]!='\0')
    {
        str[i] = str[i] -1;
        printf("%c", str[i]);
        i++;
    }
    
}


void reverse(char *str)
{
    int len = strlen(str);
    int i = 0; 
    int j = len-1;
    for (i = 0; i < len/2; i++){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

int area(struct rectangle rec){
    printf("%d\n", rec.lowerRight.x - rec.upperLeft.x);
    printf("%d\n", rec.lowerRight.y - rec.upperLeft.y);
    return (rec.lowerRight.x - rec.upperLeft.x) * (rec.lowerRight.y - rec.upperLeft.y);
}


int is_point_with_rec(struct rectangle rec, struct Point point){

    return (point.x >= rec.upperLeft.x && point.x <= rec.lowerRight.x && point.y >= rec.upperLeft.y && point.y <= rec.lowerRight.y);
}

int countOccurrences(struct node *list, int n) {

    int count = 0;
    struct node *current = list;
    while (current != NULL)
    {
        if (current->value == n)
        {
            count++;
        }
        current = current->next;
    }
    return count;
    
}

void removeSecond(struct node *list) {
    struct node *p = list->next->next;
    struct node *q = list->next;
    q->next = NULL;
    free(q);
    list->next = p;
}


char* duplicate(char* str)  {
    char *tmp = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;
    while (str[i]!='\0')
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';

    return tmp;
}  

// int max(struct node *list) {

//     struct node *current = list;
//     int max = list->value;
//     // printf("%d\n", max);
//     while (current!=NULL)
//     {
//         // printf("%d\n", current->value);
//         if (current->value > max)
//         {
//             max = current->value;
//             // printf("%d\n", max);
//         }
        
//         current = current->next;
//     }
//     return max;
// }


int max(struct node *list) {

    struct node *current;
    int max = list->value;
    for(current = list; current != NULL; current = current->next)
    {
        if (current->value > max)
        {
            max = current->value;
        }
    }
    return max;
}
    


int main(int argc, char const *argv[])
{

    //solution 01
    printf("solution 01\n");
    char str[] = "helloworld";
    strTrans(str);
    printf("\n");

    //solution 02
    printf("solution 02\n");
    reverse(str);
    printf("%s\n", str);
    
        
    // solution 03
    printf("solution 03\n");
    struct rectangle rec = {{0, 0}, {10, 10}};
    int rec_area = area(rec);
    printf("%d\n", rec_area);    

    //solution 04
    printf("solution 04\n");
    struct Point point = {11, 5};
    if (is_point_with_rec(rec, point)){
        printf("in\n");
    }else{
        printf("out\n");
    }


    //sulution 05
    printf("sulution 05\n");
    printf("%s\n", str);
    char* str2 = duplicate(str);
    printf("%s\n", str2);

    //sulution 06
    printf("sulution 06\n");
    struct node *list = malloc(sizeof(struct node));
    list->value = 1;
    list->next = malloc(sizeof(struct node));
    list->next->value = 2;
    list->next->next = malloc(sizeof(struct node));
    list->next->next->value = 1;
    list->next->next->next = NULL;
    printf("%d\n", countOccurrences(list, 1));
    
    //sulution 07
    printf("sulution 07\n");
    struct node *p;
    while (list)
    {
        p = list->next;
        free(list);
        list = p;
    }
    // printf("%d\n",list->value); // error

    //sulution 08
    printf("sulution 08\n");
    struct node *first = malloc(sizeof(struct node));
    first->value = 1;
    first->next = malloc(sizeof(struct node));
    first->next->value = 2;
    first->next->next = malloc(sizeof(struct node));
    first->next->next->value = 3;
    first->next->next->next = malloc(sizeof(struct node));
    first->next->next->next->value = 4;
    first->next->next->next->next = NULL;
    removeSecond(first);
    printf("%d\n", first->value);
    printf("%d\n", first->next->value);
    printf("%d\n", first->next->next->value);
    
    //sulution 09
    printf("sulution 09\n");

    int max_value = max(first);
    printf("%d\n", max_value);

    //sulution 10
    printf("sulution 10\n");
    char *str1 = "hello";  
    char arr[] = "hello";
    printf("%d \t %d\n", sizeof(str1), sizeof(arr));// predict 5, 1  actual 8, 6
    printf("%d \n", sizeof(arr[0]));  // predict 1,  actual 1
    // arr = str1; //predict error error: assignment to expression with array type
    // str1 = arr; //predict true : true
    arr[0] = 'j'; //predict true
    // str1[0] = 'j'; //predict error
    printf("%s \t %s\n", str1, arr);

    // arr = str;    str = arr;     str[0] = 'j';     arr[0] = 'j';


    return 0;
}

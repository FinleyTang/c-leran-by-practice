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


int main(int argc, char const *argv[])
{

    //solution 01
    char str[] = "helloworld";
    strTrans(str);
    printf("\n");

    //solution 02
    reverse(str);
    printf("%s\n", str);
    
        
    // solution 03
    struct rectangle rec = {{0, 0}, {10, 10}};
    int rec_area = area(rec);
    printf("%d\n", rec_area);    

    //solution 04
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
    struct node *list = malloc(sizeof(struct node));
    list->value = 1;
    list->next = malloc(sizeof(struct node));
    list->next->value = 2;
    list->next->next = malloc(sizeof(struct node));
    list->next->next->value = 1;
    list->next->next->next = NULL;
    printf("%d\n", countOccurrences(list, 1));




    
    return 0;
}

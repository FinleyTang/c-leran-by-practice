#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_values(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void swap_strings(char* str_1, char* str_2){

    char *temp = malloc(strlen(str_1)+1);
    for (size_t i = 0; i < strlen(str_1); i++)
    {
        temp[i] = str_1[i]; 
    }
    temp[strlen(str_1)] = '\0';

    for (size_t i = 0; i < strlen(str_2); i++)
    {
        str_1[i] = str_2[i]; 
    }
    str_1[strlen(str_2)] = '\0';

    for (size_t i = 0; i < strlen(temp); i++)
    {
        str_2[i] = temp[i]; 
    }
    str_2[strlen(temp)] = '\0';
}

void swap_strings_02(char** str_1, char** str_2){
    char * temp = *str_1;
    *str_1 = *str_2;
    *str_2 = temp;
 }

//arr[] ={2,5,1,4,7}
void sort(int *ptr,int size){
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {
            if (ptr[j]<=ptr[i])
            {
                int tmp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = tmp;
            }
            
        }
    }
    
}

void swap_int(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse_int(int *ptr, int size){
    for (size_t i = 0; i < size/2; i++)
    {
        // printf("%d\t", ptr[i]);
        // printf("%d\t\n",  ptr[size-i-1]);

        swap_int(&ptr[i], &ptr[size-i-1]);
        // printf("%d\t", ptr[i]);
        // printf("%d\t\n",  ptr[size-i-1]);
    }
}


void swap_char(char*a, char* b){
    char* tmp = a;
    *a =*b;
    *b = *tmp;
}

void reverse_str(char* ptr, int len){
    for (size_t i = 0; i < len/2; i++)
    {
        // swap_char(&ptr[i], &ptr[len-i-1]);
        printf("%c\t", ptr[i]);
        printf("%c\t\n",  ptr[len-i-1]);
        char tmp = ptr[i];
        ptr[i] = ptr[len-i-1];
        ptr[len-i-1] = tmp;
        printf("%c\t", ptr[i]);
        printf("%c\t\n",  ptr[len-i-1]);
    }
    printf("%s\n", ptr);
}
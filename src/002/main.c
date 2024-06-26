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



int main(int argc, char const *argv[])
{

    // solution 01 Write a function to swap values of two in variables by calling a function. (TSRN)
    printf("=======solution 01========\n");
    int m = 1;
    int n = 2;
    swap_values(&m, &n);
    printf("m: %d n: %d\n",m, n);
    
    //solution 02 Write a function to swap strings of two char arrays by calling a functions. (TSRN)
    printf("=======solution02=========\n");


    char str_1[] = "str_1";
    char str_2[] = "str_2";
    swap_strings(str_1,str_2);
    printf("str1: %s\n", str_1);
    printf("str2: %s\n", str_2);
    char *str_a = "stra";
    char *str_b = "strb";
    swap_strings_02(&str_a, &str_b);
    printf("str_a: %s\n", str_a);
    printf("str_b: %s\n", str_b);
    char *str1 = (char *)malloc(5 * sizeof(char));
    char *str2 = (char *)malloc(5 * sizeof(char));
    
    // 初始化字符串
    strcpy(str1, "str1");
    strcpy(str2, "str2");

    swap_strings_02(&str1, &str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    

    //solution03 Write a function to sort an array of int type values using pointers
    printf("==============solution03============\n");
    int arr[] ={2,5,1,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
     printf("\n");
    sort(arr,size);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    // 中间部分看了一下略过

    //solution 09 Write a program to print the elements of an array in reverse order using a pointer.
    printf("==============solution09============\n");
    reverse_int(arr, size);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    //solution 10  Write a program to print a string in reverse using a pointer.
    printf("==============solution10============\n");
    char str_orign[] = "origin";
    printf("%s\n", str_orign);
    reverse_str(str_orign, strlen(str_orign));
    printf("%s\n", str_orign);



    return 0;

}

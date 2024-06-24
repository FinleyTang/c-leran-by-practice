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

// void swap_strings_02(char** str_1, char** str_2){
//     char * temp = *str_1;
//     *str_1 = *str_2;
//     *str_2 = temp;
// }


int main(int argc, char const *argv[])
{

    // solution 01
    int m = 1;
    int n = 2;
    swap_values(&m, &n);
    printf("m: %d n: %d\n",m, n);
    
    //solution 02

    char str_1[] = "str_1";
    char str_2[] = "str_2";
    swap_strings(str_1,str_2);
    printf("str1: %s\n", str_1);
    printf("str2: %s\n", str_2);

    // swap_strings_02(&str_1, &str_2);
    // printf("str1: %s\n", str_1);
    // printf("str2: %s\n", str_2);

    
    
    return 0;

}

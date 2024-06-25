
# Mynotes

## 处理字符串数组（字符数组）时，不能简单地交换指针
当处理字符串数组（字符数组）时，我们不能简单地交换指针，因为字符数组是局部变量，它们的地址是固定的。指针交换方法在处理字符指针时更有效，但在处理字符数组时并不适用。下面是详细解释和两种情况下的代码示例：

字符指针（可以交换指针）：
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_string_pointers(char** str1, char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {
    char *str1 = strdup("Hello");
    char *str2 = strdup("World");

    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);

    swap_string_pointers(&str1, &str2);

    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);

    free(str1);
    free(str2);

    return 0;
}

```

在这种情况下，我们可以交换指针，因为 str1 和 str2 是指向字符串的指针，我们可以通过交换指针来交换它们指向的内容。

字符数组（不能交换指针）
```
#include <stdio.h>
#include <string.h>

void swap_strings(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char temp[len1 + 1];  // 临时数组存储str1
    strcpy(temp, str1);

    if (len1 > len2) {
        memset(str1 + len2, 0, len1 - len2);
    }
    strcpy(str1, str2);

    if (len2 > len1) {
        memset(str2 + len1, 0, len2 - len1);
    }
    strcpy(str2, temp);
}

int main() {
    char str1[] = "str_1";
    char str2[] = "str_2";

    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);

    swap_strings(str1, str2);

    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}

```


当处理字符串数组（字符数组）时，我们不能简单地交换指针，因为字符数组是局部变量，它们的地址是固定的。指针交换方法在处理字符指针时更有效，但在处理字符数组时并不适用。下面是详细解释和两种情况下的代码示例：

字符指针（可以交换指针）：
c
复制代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_string_pointers(char** str1, char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {
    char *str1 = strdup("Hello");
    char *str2 = strdup("World");

    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);

    swap_string_pointers(&str1, &str2);

    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);

    free(str1);
    free(str2);

    return 0;
}
在这种情况下，我们可以交换指针，因为 str1 和 str2 是指向字符串的指针，我们可以通过交换指针来交换它们指向的内容。

字符数组（不能交换指针）：
c
复制代码
#include <stdio.h>
#include <string.h>

void swap_strings(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char temp[len1 + 1];  // 临时数组存储str1
    strcpy(temp, str1);

    if (len1 > len2) {
        memset(str1 + len2, 0, len1 - len2);
    }
    strcpy(str1, str2);

    if (len2 > len1) {
        memset(str2 + len1, 0, len2 - len1);
    }
    strcpy(str2, temp);
}

int main() {
    char str1[] = "str_1";
    char str2[] = "str_2";

    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);

    swap_strings(str1, str2);

    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}
在这种情况下，我们不能简单地交换 str1 和 str2 的地址，因为它们是局部数组，其地址在内存中是固定的。我们需要通过复制内容来交换它们的值。

总结：

对于字符指针，我们可以通过交换指针来交换字符串。
对于字符数组，我们需要通过复制内容来交换字符串。

## C语言中 获得数组长度
1、c语言中，定义数组后可以用sizeof命令获得数组的长度（可容纳元素个数）。
例如：
```
double a[] = {1,2,3,4};
int length;
length=sizeof(a)/sizeof(a[0]); //数组占内存总空间，除以单个元素占内存空间大小
printf(“length of a=%d”, length ); //输出length of a=4
```

2、但是，通过传递数组名参数到子函数中，以获得数组长度是不可行的。

例如：
```
int getLength(int a[]){
int length;
length=sizeof(a)/sizeof(a[0]); //这样是错误的，得到的结果永远是1
return length;
}

```

因为，a是函数参数，到了本函数中，a只是一个指针（地址，系统在本函数运行时，是不知道a所表示的地址有多大的数据存储空间，这里只是告诉函数：一个数据存储空间首地址），所以，sizoef(a)的结果是指针变量a占内存的大小，一般在32位机上是4个字节。a[0]是int类型，sizeof(a[0])也是4个字节，所以，结果永远是1。


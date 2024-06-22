```
#include <stdio.h>

int main() {
    char *str1 = "hello";  
    char arr[] = "hello";
    printf("%lu \t %lu\n", sizeof(str1), sizeof(arr));
    return 0;
}
```
结果：
```
8    6
```

解释：

```
char *str1 = "hello";:
```

str1 是一个指针，指向一个字符串常量 "hello"。
sizeof(str1) 返回的是指针 str1 的大小，而不是它指向的字符串的大小。
在 64 位系统上，指针的大小通常是 8 字节，所以 sizeof(str1) 返回 8。在 32 位系统上，这个值可能是 4。

```
char arr[] = "hello";:
```

arr 是一个字符数组，初始化为字符串 "hello"。
sizeof(arr) 返回的是整个数组的大小，包括字符串末尾的空字符 '\0'。
字符串 "hello" 包含 5 个字符加上一个终止符 '\0'，所以 sizeof(arr) 返回 6。
总结
sizeof(str1) 返回指针的大小，在 64 位系统上通常是 8。
sizeof(arr) 返回字符数组的大小，包括终止符 '\0'，所以是 6。
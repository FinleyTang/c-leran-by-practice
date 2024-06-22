# Practice with arrays, structs, pointers and linked lists

1. Assume that we've declared and initialized a string as follows:
Write C code that loops over the string (i.e., the char array) and sets each char to the char immediately preceding it in the alphabet. You may assume that all the characters in the string are letters (and not 'a' or 'A'). For example, if we initialized the string like this:
char str[] = "hello";
Then the output should be: gdkkn

2. Write a function that takes a string as its argument, and reverses the string in place. So if your function is called like this:
char s[] = "hello";

rev(s);
printf("%s\n", s);
The output will be olleh
You can call strlen() (from string.h) in your code.

3. Consider the following structs:
struct point {
   int x;
   int y;
};
struct rectangle {
   struct point upperLeft;
   struct point lowerRight;
};
struct point represents the x and y coordinates of a point in two dimensional space. The points in the struct rectangle represent the points at the upper left and lower right corners of a rectangle in two dimensional space. Write a function area() that takes a rectangle struct as its parameter, and returns the area of the rectangle.

4. Given the same structs as in the previous question, write a function that takes a struct rectangle r and a struct point p, and returns true if p lies within r and false otherwise.

5. Write a function named duplicate() that uses dynamic memory allocation to create a copy of a string. For example, the call
p = duplicate(str);
would allocate space for a string the same length as str, copy the contents of str into the new string, and return a pointer to it. Have duplicate() return NULL if the memory allocation fails.

6. Given the struct node below:
struct node {
    int value;
    struct node *next;
};
Write the following function:
int countOccurrences(struct node *list, int n) {...}
which returns the number of occurrences of the integer n in the list. The first parameter is the linked list pointer (i.e., it points to the first element in the linked list.)

7. Assume that first is the list pointer for a linked list (so p points to the first node in the list.) struct node is declared in question 6. Write C code that deletes all nodes in the list and frees the memory for all nodes. Consider the code below. It is incorrect - how would you fix it?
struct node *p;
for(p = first; p!=NULL; p = p -> next)  free(p);

8. Write a function that takes the pointer to a linked list of type struct node (as defined above), and removes the second node in the list. (Don't forget to call free()). You may assume that the list has at least two elements in it.
// pre: list != NULL and list points to a linked list containing at least two nodes
void removeSecond(struct node *list) {
    ...
}

9. Write a function max() that takes a pointer to a linked list and returns the maximum value stored in a list.
int max(struct node *list) {
...
}

10. Consider the following two statements:
char *str = "hello";  char arr[] = "hello";
a) What is printed on kamek when the following statement is executed? What do the printed values mean?
printf("%zu \t %zu\n", sizeof(str), sizeof(arr));

b) Which of the following (if any) will produce a compilation error?
arr = str;    str = arr;     str[0] = 'j';     arr[0] = 'j';

#if !defined SHAPE_H
#define SHAPE_H

struct Point
{
    int x;
    int y;
};

struct rectangle 
{
    struct Point upperLeft;
    struct Point lowerRight;
};


#endif // MACRO

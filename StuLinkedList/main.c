#include <stdio.h>
#include <stdlib.h>
struct StuInfo
{
    char id[20];
    char name[20];
    char sex;    //w = female; m = male;
};

//Student's score
struct StuScore
{
    int chinese;
    int math;
    int English;
    float average;
};

//LinkedList
struct node
{
    struct StuInfo info;
    struct StuScore score;
    int nodeId;     //To tag each node;
    struct node * next;    //Point to the next;
};
typedef struct node node;

int main()
{
    printf("Hello world!\n");
    return 0;
}

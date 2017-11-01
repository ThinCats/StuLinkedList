#include <stdio.h>
#include <stdlib.h>
#include "stuList.h"



void printSuc(void);
void printWelcome(void);
void printStars(int n);
int main()
{
    node *stuList = (node *)malloc(sizeof(node));

    //UI:
    //putchar('\n');

    int n = 1;
    while(n)
    {

    printWelcome();
    scanf("%d", &n);
    switch(n)
    {
    case 0:
        return 0;
        break;
    case 1:
        {
            printf("How many students do you want to insert?\n");
            int n;
            scanf("%d", &n);
            stuList = creatAList(n);
            printSuc();
            break;
        }
    case 2:
        {
            if(calTheAve(stuList) == 1)
                printSuc();
            break;
        }
    case 3:
        {
            printf("You want to add after which one?(I mean the nodeId\n>>)");
            int nodeId;
            scanf("%d", &nodeId);

            if((stuList = insertANode(stuList, nodeId)));
                printSuc();
        }
    case 4:
        {
            printf("You want to delete which one?(I mean the nodeId\n>>)");
            int nodeId;
            scanf("%d", &nodeId);

            if(stuList = deleteAnode(stuList, nodeId))
                printSuc();
        }
    case 5:
        {
            printAList(stuList);
            break;
        }
    case 6:
        {
            //if(stuList = orderAList(stuList))
                printSuc();
        }
    }
    }
    return 0;
}

void printSuc(void)
{
    printf("\nIt's successful. Print it to see\n\n");
}

void printWelcome(void)
{
    int n = 50;
    printStars(n);
    //purchar('\n');
    printf("\t   Please choose what you want:\n");
    printf("\t\t1. Insert\n");
    printf("\t\t2. Calculate the Average Score\n");
    printf("\t\t3. Add a new student\n");
    printf("\t\t4. Delete an old student\n");
    printf("\t\t5. Print The table\n");
    printf("\t\t6. Order them by the Ave score\n");
    printf("\t\t0. Exit\n");
    printStars(n);
    printf(">>>");
}

void printStars(int n)
{
    int i = 0;
    for(;i < n;i++)
        printf("*");
    putchar('\n');
}

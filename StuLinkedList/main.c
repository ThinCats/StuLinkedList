#include <stdio.h>
#include <stdlib.h>
#include "stuListModel.h"



void printSuc(void);
void printWelcome(void);
void printStars(int n);
int main()
{
    node *stuList = (node *)malloc(sizeof(node));

    //UI:
    printWelcome();
    putchar('\n');

    int n;
    scanf("%d", &n);

    switch(n)
    {
    case 1:
        {
            creatAList(stuList);
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
        }
    case 6:
        {
            if(stuList = orderAList(stuList))
                printSuc();
        }
    }

    return 0;
}

void printSuc(void)
{
    printf("It's successful. Print it to see\n");
}

void printWelcome(void)
{
    int n = 15;
    printStars(n);
    //purchar('\n');
    printf("\t   Please choose what you want:\n");
    printf("\t\t1. insert\n");
    printf("\t\t2. Calculate the Average Score\n");
    printf("\t\t3. Add a new student\n");
    printf("\t\t4. Delete an old student\n");
    printf("\t\t5. Print The table\n");
    printf("\t\t6. Order them by the Ave score\n");
    printStars(n);
    printf(">>>");
}

#include <stdio.h>
#include <stdlib.h>
#include "stuList.h"



void printSuc(void);
void printWelcome(void);
void printStars(int n);
int main()
{
    //node *stuList = (node *)malloc(sizeof(node));
    node *stuList;
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
            printf("How many students do you want to insert?(0 to exit)\n");
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
            printf("You want to add before which one?(I mean the nodeId)(0 to exit)\n>>)");
            int nodeId;
            scanf("%d", &nodeId);

            if((stuList = insertANode(stuList, nodeId)));
                printSuc();

            break;
        }
    case 4:
        {
            printf("You want to delete which one?(I mean the nodeId)(0 to exit)\n>>)");
            int nodeId;
            scanf("%d", &nodeId);

            if(stuList = deleteAnode(stuList, nodeId))
                printSuc();

            break;
        }
    case 5:
        {
            printAList(stuList);
            break;
        }
    case 6:
        {
            if(stuList = orderAList(stuList))
                printSuc();
            break;
                //Bug:
                //printf("Sorry, I still can't fix this bug\n\n");
        }
    case 7:         //Delete data in chosen student
        {
            int switchNode;
            int switchNum;

            //UI
            printf("---------Look down------------------\n");
            printf("Students:\n");
            printAList(stuList);
            printf("\nDatas:\n");
            printf("\n1.nodeId \t2.  Name \t3.  Sex  \t4.Chinese\t5.  Math \t6.English\t7.Average\t\n\n");
            printf("Which student do you want to delete?(node id)?(0 to exit)\n>>>");
            scanf("%d", &switchNode);
            printf("Which index do you want to delete?(0 to exit)\n>>>");
            scanf("%d", &switchNum);

            if(stuList = delNewData(stuList, switchNum, switchNode));
                printSuc();

            break;
        }

    default:
            printf("Wrong input!\n");
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
    printf("\t\t7. Delete a student's score\n");
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

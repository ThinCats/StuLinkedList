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

//Create and record the data;
node * creatAList(node * head);

node * deleteAnode(node * head, int nodeId);

void printAList(node * head);

//insert a node inside some ids(中文来讲就是在某序号下一个插入节点)
node * insertANode(node * head, int nodeId_before);

//So We need to reId all the nodes
//startId means whether you want to start with 1 or 0;
node * reIdList(node * head, int startId);

//calculate the average score
//return whether is successful
//the head is not changed
int calTheAve(node * head);

//Order the list
node * orderAList(node * head);


void printSuc(void);
void printWelcome(void);
void printStars(int n);
int main()
{
    node *stuList = (node *)malloc(sizeof(node));

    //UI:
    printWelcome();

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
    printf("\t\tPlease choose what you want:\n")
    printf("\t\t1. insert\n");
    printf("\t\t2. Calculate the Average Score\n");
    printf("\t\t3. Add a new student\n");
    printf("\t\t4. Delete an old student\n");
    printf("\t\t5. Print The table\n");
    printf("\t\t6. Order them by the Ave score\n");
    printStars(n);
}

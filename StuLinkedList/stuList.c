#include<stdio.h>
#include "stuList.h"
#include "myIput.h"
node * creatAList(int n)
{
    int setedId = 1;
    //current and previous
    node * current;
    node * prev;
    node * head = NULL;

    //printf("When you input your name as end, we will end the insert.\n");
    int i = 0;
    while(i++ < n)
    {
        current = (node*)(malloc(sizeof(node)));     //新建一个链表节点， 用来储存数据;

        //设置头节点
        if(head == NULL)
            head = current;
        //设置联系
        else prev->next = current;

        //设置下一节点
        prev = current;

        //输入数据
        getData(current);

        //setId
        current->nodeId = setedId++;

        //initAve
        current->score.average = 0;


    }
    //建立序号
    //head = reIdList(head,1);

    //释放多于内存
    free(current);
    //设置尾结点
    prev->next = NULL;

    return head;
}

void getData(node * current)
{


        //获取name
        getchar();
        printf("Please input your name:\n>>>");
        gets(current->info.name);
        //scanf("\n5s", current->info.name);

        //获取学号
        //getchar();
        printf("Please input your id:\n>>>");
        gets(current->info.id);
        //scanf("%s", current->info.id);

        //获取性别
        //getchar();
        printf("Please input your sex:\n>>>");
        //current->info.sex = getchar();
        //scanf("%5s", current->info.sex);
        gets(current->info.sex);

        //获取语文成绩
        printf("Please input your chinese:\n>>>");
        scanf("%d", &current->score.chinese);

        //获取语文成绩
        printf("Please input your math:\n>>>");
        scanf("%d", &current->score.math);

        //获取英语成绩
        printf("Please input your English:\n>>>");
        scanf("%d", &current->score.english);

}

node * deleteAnode(node * head, int nodeId)
{
    node *current;
    node *prev;
    current = head;
    while(current->nodeId != nodeId)
    {
        //储存上一节点
        prev = current;
        //遍历下一节点
        current = current -> next;
    }
    //重新建立联系
    prev->next = current->next;
    free(current);

    head = reIdList(head,1);
    return head;
}

void printAList(node * head)
{
        node *current;
        current = head;

        while(current != NULL)
        {
        printf("------------------------------------------------------------------------------------------------------\n");
        printf("id = %d\tname = %s\tstuId = %s\tsex = %s\tchinese = %d\t math = %d\t eng = %d\t Ave = %.2f\n",current->nodeId ,(current->info.id)
               ,current->info.name, current->info.sex, current->score.chinese, current->score.math, current->score.english,
               current->score.average);
        current = current->next;
        }


}

node * insertANode(node * head, int nodeId)
{
    nodeId--; //让current变为之后， prev变为之前
    node * newNode;  //New a new node
    node * current;
    node * prev;


    current = head;
    //getData
    getData(newNode);

    //找到特定位置
    while(current->nodeId != nodeId)
    {
        prev = current;
        current = current->next;
    }

    //建立联系
    //newNode 插入current 和 prev中央
    prev->next = newNode;
    newNode->next = current;

    //head = reIdList(head,1);
    return head;


}

node * reIdList(node * head, int startId)
{
    node * current;
    current = head;

    //遍历链表
    while(current != NULL)
    {
        current->nodeId = startId;
        startId++;
        current = current->next;
    }

    return head;
}

int calTheAve(node * head)
{
    node * current;
    while(current != NULL)
    {
        float sum = 0;
        sum = (current->score.chinese + current->score.math + current->score.english);
        current->score.average = sum / 3.0;
        current = current->next;
    }

    return 1;
}

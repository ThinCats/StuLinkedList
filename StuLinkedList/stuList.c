#include<stdio.h>
#include "stuList.h"
node * creatAList(void)
{
    //current and previous
    node * current;
    node * prev;
    node * head = NULL;

    printf("When you input your name as end, we will end the insert.\n");
    while(1)
    {
        current = (node*)(malloc(sizeof(node)));     //新建一个链表节点， 用来储存数据;

        //设置头节点
        if(head == NULL)
            head = current;
        //设置联系
        else prev->next = current;

        //设置下一节点
        prev = current;

        //获取name
        printf("Please input your name:\n>>>");
        scnaf("%s", current->info->name;
        if(current->info->name == "end")             //There's something wrong
            break;

        //获取学号
        printf("Please input your id:\n>>>");
        scnaf("%s", current->info->id);

        //获取性别
        printf("Please input your sex:\n>>>");
        scnaf("%c", current->info->sex);

        //获取语文成绩
        printf("Please input your chinese:\n>>>");
        scnaf("%s", current->score->chinese);

        //获取语文成绩
        printf("Please input your math:\n>>>");
        scnaf("%s", current->score->math);

        //获取英语成绩
        printf("Please input your English:\n>>>");
        scnaf("%s", current->score->english);

    }
    //释放多于内存
    free(current);
    //设置尾结点
    prev->next = NULL;
}

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
        current = (node*)(malloc(sizeof(node)));     //�½�һ������ڵ㣬 ������������;

        //����ͷ�ڵ�
        if(head == NULL)
            head = current;
        //������ϵ
        else prev->next = current;

        //������һ�ڵ�
        prev = current;

        //��ȡname
        printf("Please input your name:\n>>>");
        scnaf("%s", current->info->name;
        if(current->info->name == "end")             //There's something wrong
            break;

        //��ȡѧ��
        printf("Please input your id:\n>>>");
        scnaf("%s", current->info->id);

        //��ȡ�Ա�
        printf("Please input your sex:\n>>>");
        scnaf("%c", current->info->sex);

        //��ȡ���ĳɼ�
        printf("Please input your chinese:\n>>>");
        scnaf("%s", current->score->chinese);

        //��ȡ���ĳɼ�
        printf("Please input your math:\n>>>");
        scnaf("%s", current->score->math);

        //��ȡӢ��ɼ�
        printf("Please input your English:\n>>>");
        scnaf("%s", current->score->english);

    }
    //�ͷŶ����ڴ�
    free(current);
    //����β���
    prev->next = NULL;
}

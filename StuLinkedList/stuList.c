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
        current = (node*)(malloc(sizeof(node)));     //�½�һ������ڵ㣬 ������������;

        //����ͷ�ڵ�
        if(head == NULL)
            head = current;
        //������ϵ
        else prev->next = current;

        //������һ�ڵ�
        prev = current;

        //��������
        getData(current);

        //setId
        current->nodeId = setedId++;

        //initAve
        current->score.average = 0;


    }
    //�������
    //head = reIdList(head,1);

    //�ͷŶ����ڴ�
    free(current);
    //����β���
    prev->next = NULL;

    return head;
}

void getData(node * current)
{


        //��ȡname
        getchar();
        printf("Please input your name:\n>>>");
        gets(current->info.name);
        //scanf("\n5s", current->info.name);

        //��ȡѧ��
        //getchar();
        printf("Please input your id:\n>>>");
        gets(current->info.id);
        //scanf("%s", current->info.id);

        //��ȡ�Ա�
        //getchar();
        printf("Please input your sex:\n>>>");
        //current->info.sex = getchar();
        //scanf("%5s", current->info.sex);
        gets(current->info.sex);

        //��ȡ���ĳɼ�
        printf("Please input your chinese:\n>>>");
        scanf("%d", &current->score.chinese);

        //��ȡ���ĳɼ�
        printf("Please input your math:\n>>>");
        scanf("%d", &current->score.math);

        //��ȡӢ��ɼ�
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
        //������һ�ڵ�
        prev = current;
        //������һ�ڵ�
        current = current -> next;
    }
    //���½�����ϵ
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
    nodeId--; //��current��Ϊ֮�� prev��Ϊ֮ǰ
    node * newNode;  //New a new node
    node * current;
    node * prev;


    current = head;
    //getData
    getData(newNode);

    //�ҵ��ض�λ��
    while(current->nodeId != nodeId)
    {
        prev = current;
        current = current->next;
    }

    //������ϵ
    //newNode ����current �� prev����
    prev->next = newNode;
    newNode->next = current;

    //head = reIdList(head,1);
    return head;


}

node * reIdList(node * head, int startId)
{
    node * current;
    current = head;

    //��������
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

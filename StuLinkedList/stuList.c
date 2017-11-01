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
        //current->nodeId = setedId++;

        //initAve
        current->score.average = 0;


    }
    prev->next = NULL;
    //�������
    head = reIdList(head,1);

    //�ͷŶ����ڴ�
    free(current);
    //����β���


    return head;
}

void getData(node * current)
{



        //��ȡѧ��   //�������޷���������⣡����������
        getchar();
        //printf("Please input your id:\n>>>");
        //gets(current->info.myid);
        //scanf("%d", &current->info.myid);

        //��ȡname
        //getchar();
        printf("Please input your name:\n>>>");
        gets(current->info.name);
        //scanf("\n5s", current->info.name);

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

        printf("\n********************That's good*********************\n\n");
}

node * deleteAnode(node * head, int nodeId)
{
    if(nodeId == 0)
    {
        printf("Nothing has been done!\n");
        return head;
    }

    node *current;
    node *prev;
    current = head;


    if(current->next->next == 1)
    {
        head = NULL;
        printf("\nNow all is empty, please recreate another one\n");
        return head;
    }
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
        printf("nodeId = %d\tname = %s\tsex = %s\tchinese = %d\t math = %d\t eng = %d\t Ave = %.2f\n",current->nodeId
               ,current->info.name, current->info.sex, current->score.chinese, current->score.math, current->score.english,
               current->score.average);
        current = current->next;
        }


}

node * insertANode(node * head, int nodeId)
{
    if(nodeId == 0)
    {
        printf("Nothing has been done!\n");
        return head;
    }

    if(nodeId == 1)        //nodeId--����ܻᵼ�·Ƿ������ʣ�Խ�磩
    {
        nodeId = 2;
    }


    nodeId--; //��current��Ϊ֮�� prev��Ϊ֮ǰ
    node * newNode = (node*)malloc(sizeof(node *)); //New a new node
    //newNode->next = NULL;
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
    if(nodeId != 1)               //nodeId = 1 has a different situation
        prev->next = newNode;
    newNode->next = current;

    if(nodeId == 1)
        head = newNode;

    //reId;
    head = reIdList(head,1);
    return head;


}

node * reIdList(node * head, int startId)
{
    node * current;
    current = head;

    //��������
    while(current != NULL)
    {
        (current->nodeId) = startId;
        startId++;
        if(current->next == NULL)
            break;
        current = current->next;
    }

    return head;

}

int calTheAve(node * head)
{
    node * current = head;
    while(current != NULL)
    {
        float sum = 0;
        sum = (current->score.chinese + current->score.math + current->score.english);
        current->score.average = sum / 3.0;
        current = current->next;
    }

    return 1;
}

node * orderAList(node * head)
{
    int i;
    int j;
    int count = 0;
    node * current = head;
    node * prev;
    node temp;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    for(i=0;i<count;i++)
    {
        for(j=0;j<count;j++)
        {
            prev = current;
            current = current->next;
            if(prev->score.average < current->score.average)
            {
                temp.score = prev->score;
                temp.info = prev->info;

                prev->score = current->score;
                prev->info = current->info;

                current->score = temp.score;
                current->info = temp.info;

            }
        }

        current = head;
    }


        head = reIdList(head,1);

        return head;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AQueue.h"
/*
typedef struct Aqueue
{
    void* data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;
*/


//��ʼ������
void InitAQueue(AQueue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    memset(Q->data, 0, sizeof(void*) * MAXQUEUE);
    return;
}

//���ٶ���
void DestoryAQueue(AQueue* Q)
{
    free(Q);
    Q = NULL;
}

//�������Ƿ�����
Status IsFullAQueue(const AQueue* Q)
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//�ж϶����Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue* Q)
{
    if (Q->rear == Q->front)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue* Q, void* e)
{
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    if (datatype[Q->front] == 'a')
    {
        memcpy(e, Q->data[Q->front], sizeof(int));
    }
    if (datatype[Q->front] == 'b')
    {
        memcpy(e, Q->data[Q->front], sizeof(double));
    }
    if (datatype[Q->front] == 'c')
    {
        memcpy(e, Q->data[Q->front], sizeof(char)*100);
    }

    
    return TRUE;
}

//�ж϶��г���
int LengthAQueue(AQueue* Q)
{
    return Q->length;
}

//���
Status EnAQueue(AQueue* Q, void* data)
{
    //����������
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        return FALSE;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->length++;
    return TRUE;
}

//����
Status DeAQueue(AQueue* Q)
{
    //������Ϊ��
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->length--;
    return TRUE;
}

//��ն���
void ClearAQueue(AQueue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    return;
}

//��������
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int temp))
{
    if (Q->front == Q->rear)
    {
        printf("�ö���Ϊ��!\n");
        return FALSE;
    }
    int temp = Q->front;
    printf("�ö�������Ϊ:\n");
    while (temp != Q->rear && temp != MAXQUEUE)
    {
        foo(Q->data[temp],temp);
        temp++;
    }
    if (temp!=Q->rear)
    {
        temp = 0;
        while (temp != Q->rear)
        {
            foo(Q->data[temp],temp);
            temp++;
        }
        printf("\n");
        return TRUE;
    }
    else
    {
        printf("\n");
        return TRUE;
    }
}

//��ӡ����
void APrint(void* q,int temp)
{
    if (datatype[temp] == 'a')
    {
        printf("%d\n", *(int*)q);
        return;
    }
    if (datatype[temp] == 'b')
    {
        printf("%lf\n", *(double*)q);
        return;
    }
    if (datatype[temp] == 'c')
    {
        printf("%s\n", (char*)q);
        return;
    }
}

//��ӡ�˵�
void printMenu()
{
    printf("==========hahahahahaha         ==========\n");
    printf("==========1.���               ==========\n");
    printf("==========2.����               ==========\n");
    printf("==========3.�ж϶����Ƿ�Ϊ��   ==========\n");
    printf("==========4.�ж϶����Ƿ���     ==========\n");
    printf("==========5.�鿴��ͷԪ��       ==========\n");
    printf("==========6.��ն���           ==========\n");
    printf("==========7.���ٶ��в��˳����� ==========\n");
    printf("==========8.�����г���       ==========\n");
    printf("==========9.��������           ==========\n");
    printf("==========0.�˳�               ==========\n");
    printf("�����빦�ܵĶ�Ӧ���:\n");
}

//ѡ����
Status funcChoice(char* choice)
{
    char c;
    int ret;
    ret = gets(choice);
    if (ret == 0)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }
    int i = 0;
    if (choice[0] == '\0')
    {
        return FALSE;
    }
    //ͨ����ѭ��˵��ȫ����������
    for (i = 0; choice[i] != '\0'; i++)
    {
        if (choice[i] < 48 || choice[i] > 57)
        {
            return FALSE;
        }
    }
    //��λ������3λ
    if (i > 3)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }
    int a = 0;
    a = atoi(choice);
    if (a < 0 || a>9)
    {
        return FALSE;
    }

    return TRUE;
}

//���������ж�
Status charJudge(char* a)
{
    char c;
    int ret;
    ret = gets(a);
    if (ret == 0)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }
    int i = 0;
    if (a[0] == '\0')
    {
        return FALSE;
    }
    //ͨ����ѭ��˵��ȫ����������
    for (i = 0; a[i] != '\0'; i++)
    {
        //��һλ������
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
        {

            return FALSE;
        }
        if (i != 0 && (a[i] < 48 || a[i] > 57))
        {

            return FALSE;
        }
    }
    //��λ������11λ
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }

    return TRUE;
}

//����int����
int intJudge()
{
    int d = 0;
    char a[100];
    int ret = 0;
    ret = charJudge(a);
    while (ret == 0)
    {
        printf("�����������������룺\n");
        ret = charJudge(a);
    }
    d = atoi(a);
    return d;

}

//����double�����ж�
Status doublecharJudge(char* a)
{
    char c;
    int count = 0;
    int ret;
    ret = gets(a);
    if (ret == 0)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }
    int i = 0;
    if (a[0] == '\0')
    {
        return FALSE;
    }
    //ͨ����ѭ��˵��ȫ���������ֻ�ֻ��һ��С����
    for (i = 0; a[i] != '\0'; i++)
    {
        //��һλ������
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57)&&a[i]=='.')
        {
            return FALSE;
        }
        if (i != 0 && ((a[i] < 48 || a[i] > 57)&&a[i]!='.'))
        {

            return FALSE;
        }
        if (a[i] == '.')
        {
            count++;
        }
        if (count > 1)
        {
            return FALSE;
        }
    }
    //��λ������11λ
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }

    return TRUE;
}

//����double����
double doubleJudge()
{
    double d = 0;
    char a[100];
    int ret = 0;
    ret = doublecharJudge(a);
    while (ret == FALSE)
    {
        printf("������������������!\n");
        ret = doublecharJudge(a);
    }
    d = atof(a);
    return d;
}

//����char����
Status CharJudge(char* a)
{
    gets(a);
    int i = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (i >= 101)
        {
            return FALSE;
        }
    }
    return TRUE;
}

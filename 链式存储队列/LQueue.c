#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LQueue.h"

/*
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
} LQueue;
*/

//��ʼ������
Status InitLQueue(LQueue* Q)
{
    //����ͷ�ڵ�
    Node* hNode = (Node*)malloc(sizeof(Node));
    if (hNode == NULL)
    {
        return FALSE;
    }
    hNode->next = NULL;
    hNode->data = NULL;
    hNode->type= '\0';
    Q->front = hNode;
    Q->rear = hNode;
    Q->length = 0;
    return TRUE;
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
    //������Ϊ��
    if (Q->front== Q->rear)
    {
        free(Q->front);
        Q->front = NULL;
        free(Q);
        Q = NULL;
        return;
    }
    while (Q->front->next != Q->rear)
    {
        Node* temp = Q->front->next;
        Q->front->next = temp->next;
        free(temp);
        temp = NULL;
    }
    Node* temp = Q->rear;
    free(temp);
    temp = NULL;
    free(Q);
    Q = NULL;
    return;

}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
    if (Q->front == Q->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void* e)
{
    //������Ϊ��
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    memcpy(e, Q->front->next->data, sizeof((char*)Q->front->next->data));
    return TRUE;
}

//���г���
int LengthLQueue(LQueue* Q)
{
    return Q->length;
}

//���
Status EnLQueue(LQueue* Q, void* data,char a)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("�����ڴ�ʧ��!\n");
        return FALSE;
    }
    if (a == 'a')
    {
        newNode->data = (void*)malloc(sizeof(int));
        newNode->type = 'a';
    }
    if (a == 'b')
    {
        newNode->data = (void*)malloc(sizeof(double));
        newNode->type = 'b';
    }
    if (a == 'c')
    {
        newNode->data = (void*)malloc(sizeof(char) * 100);
        newNode->type = 'c';
    }
    newNode->data = data;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    Q->length++;
    return TRUE;
}

//����
Status DeLQueue(LQueue* Q)
{
    //������Ϊ��
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    Node* temp = Q->front->next;
    Q->front->next = temp->next;
    //��ɾ����Ϊ��βԪ��
    if (Q->front->next == NULL)
    {
        Q->rear = Q->front;
    }
    free(temp);
    temp = NULL;
    Q->length--;
    return TRUE;
}

//��ն���
void ClearLQueue(LQueue* Q)
{
    //������Ϊ��
    if (Q->front == Q->rear)
    {
        return;
    }
    while (Q->front->next != Q->rear)
    {
        Node* temp = Q->front->next;
        Q->front->next = temp->next;
        free(temp);
        temp = NULL;
    }
    Node* temp = Q->rear;
    Q->front->next = NULL;
    Q->rear = Q->front;
    free(temp);
    temp = NULL;
    Q->length = 0;
    return;

}

//��������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,Node* temp))
{
    if (Q->front == Q->rear)
    {
        printf("�ö���Ϊ��!\n");
        return FALSE;
    }
    Node* temp = Q->front->next;
    while (temp != NULL)
    {
        foo(temp->data,temp);
        temp = temp->next;
    }
    printf("\n");
    return TRUE;
}

//��ӡ����
void LPrint(void* q,Node* temp)
{
    if (temp->type == 'a')
    {
        printf("%d\n", *(int*)q);
        return;
    }
    if (temp->type == 'b')
    {
        printf("%lf\n", *(double*)q);
        return;
    }
    if (temp->type == 'c')
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
    printf("==========4.�鿴��ͷԪ��       ==========\n");
    printf("==========5.��ն���           ==========\n");
    printf("==========6.���ٶ��в��˳����� ==========\n");
    printf("==========7.�����г���       ==========\n");
    printf("==========8.��������           ==========\n");
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
    if (a < 0 || a>8)
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
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
        {
            return FALSE;
        }
        if (i != 0 && ((a[i] < 48 || a[i] > 57) && a[i] != '.'))
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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LQueue.h"

/*
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;
*/

//初始化队列
Status InitLQueue(LQueue* Q)
{
    //创建头节点
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

//销毁队列
void DestoryLQueue(LQueue* Q)
{
    //若队列为空
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

//检测队列是否为空
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

//查看队头元素
Status GetHeadLQueue(LQueue* Q, void* e)
{
    //若队列为空
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    memcpy(e, Q->front->next->data, sizeof((char*)Q->front->next->data));
    return TRUE;
}

//队列长度
int LengthLQueue(LQueue* Q)
{
    return Q->length;
}

//入队
Status EnLQueue(LQueue* Q, void* data,char a)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("分配内存失败!\n");
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

//出队
Status DeLQueue(LQueue* Q)
{
    //若队列为空
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    Node* temp = Q->front->next;
    Q->front->next = temp->next;
    //若删除的为队尾元素
    if (Q->front->next == NULL)
    {
        Q->rear = Q->front;
    }
    free(temp);
    temp = NULL;
    Q->length--;
    return TRUE;
}

//清空队列
void ClearLQueue(LQueue* Q)
{
    //若队列为空
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

//遍历队列
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,Node* temp))
{
    if (Q->front == Q->rear)
    {
        printf("该队列为空!\n");
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

//打印数据
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

//打印菜单
void printMenu()
{
    printf("==========hahahahahaha         ==========\n");
    printf("==========1.入队               ==========\n");
    printf("==========2.出队               ==========\n");
    printf("==========3.判断队列是否为空   ==========\n");
    printf("==========4.查看队头元素       ==========\n");
    printf("==========5.清空队列           ==========\n");
    printf("==========6.销毁队列并退出程序 ==========\n");
    printf("==========7.检测队列长度       ==========\n");
    printf("==========8.遍历队列           ==========\n");
    printf("==========0.退出               ==========\n");
    printf("请输入功能的对应编号:\n");
}

//选择功能
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
    //通过此循环说明全部都是数字
    for (i = 0; choice[i] != '\0'; i++)
    {
        if (choice[i] < 48 || choice[i] > 57)
        {
            return FALSE;
        }
    }
    //若位数超过3位
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

//输入数据判断
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
    //通过此循环说明全部都是数字
    for (i = 0; a[i] != '\0'; i++)
    {
        //第一位不符合
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
        {

            return FALSE;
        }
        if (i != 0 && (a[i] < 48 || a[i] > 57))
        {

            return FALSE;
        }
    }
    //若位数超过11位
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }

    return TRUE;
}

//输入int数据
int intJudge()
{
    int d = 0;
    char a[100];
    int ret = 0;
    ret = charJudge(a);
    while (ret == 0)
    {
        printf("输入有误，请重新输入：\n");
        ret = charJudge(a);
    }
    d = atoi(a);
    return d;

}

//输入double数据判断
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
    //通过此循环说明全部都是数字或只有一个小数点
    for (i = 0; a[i] != '\0'; i++)
    {
        //第一位不符合
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
    //若位数超过11位
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return FALSE;
    }

    return TRUE;
}

//输入double数据
double doubleJudge()
{
    double d = 0;
    char a[100];
    int ret = 0;
    ret = doublecharJudge(a);
    while (ret == FALSE)
    {
        printf("输入有误，请重新输入!\n");
        ret = doublecharJudge(a);
    }
    d = atof(a);
    return d;
}

//输入char数据
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
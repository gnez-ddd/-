#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AQueue.h"
/*
typedef struct Aqueue
{
    void* data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;
*/


//初始化队列
void InitAQueue(AQueue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    memset(Q->data, 0, sizeof(void*) * MAXQUEUE);
    return;
}

//销毁队列
void DestoryAQueue(AQueue* Q)
{
    free(Q);
    Q = NULL;
}

//检查队列是否满了
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

//判断队列是否为空
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

//查看队头元素
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

//判断队列长度
int LengthAQueue(AQueue* Q)
{
    return Q->length;
}

//入队
Status EnAQueue(AQueue* Q, void* data)
{
    //若队列满了
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        return FALSE;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->length++;
    return TRUE;
}

//出队
Status DeAQueue(AQueue* Q)
{
    //若队列为空
    if (Q->front == Q->rear)
    {
        return FALSE;
    }
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->length--;
    return TRUE;
}

//清空队列
void ClearAQueue(AQueue* Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    return;
}

//遍历队列
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int temp))
{
    if (Q->front == Q->rear)
    {
        printf("该队列为空!\n");
        return FALSE;
    }
    int temp = Q->front;
    printf("该队列数据为:\n");
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

//打印数据
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

//打印菜单
void printMenu()
{
    printf("==========hahahahahaha         ==========\n");
    printf("==========1.入队               ==========\n");
    printf("==========2.出队               ==========\n");
    printf("==========3.判断队列是否为空   ==========\n");
    printf("==========4.判断队列是否满     ==========\n");
    printf("==========5.查看队头元素       ==========\n");
    printf("==========6.清空队列           ==========\n");
    printf("==========7.销毁队列并退出程序 ==========\n");
    printf("==========8.检测队列长度       ==========\n");
    printf("==========9.遍历队列           ==========\n");
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
    if (a < 0 || a>9)
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

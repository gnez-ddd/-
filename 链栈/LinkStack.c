#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LinkStack.h"

/*
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;
*/

//打印菜单
void printMenu()
{
	printf("==========hahahahahahahah          ==========\n");
	printf("==========1.进栈                   ==========\n");
	printf("==========2.出栈                   ==========\n");
	printf("==========3.判断栈是否为空         ==========\n");
	printf("==========4.得到栈顶元素           ==========\n");
	printf("==========5.清空栈                 ==========\n");
	printf("==========6.销毁栈并退出程序       ==========\n");
	printf("==========7.检测栈的长度           ==========\n");
	printf("==========8.遍历栈                 ==========\n");
	printf("==========0.退出                   ==========\n");
	printf("请输入功能的对应编号:\n");
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
		return ERROR;
	}
	int i = 0;
	if (a[0] == '\0')
	{
		return ERROR;
	}
	//通过此循环说明全部都是数字
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] < 48 || a[i] > 57)
		{

			return ERROR;
		}
	}
	//若位数超过11位
	if (i > 11)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}

	return SUCCESS;
}

//输入数据
int dataJudge()
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

//选择功能
Status funcChoice(char* choice)
{
	char c;
	int ret;
	ret = gets(choice);
	if (ret == 0)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}
	int i = 0;
	if (choice[0] == '\0')
	{
		return ERROR;
	}
	//通过此循环说明全部都是数字
	for (i = 0; choice[i] != '\0'; i++)
	{
		if (choice[i] < 48 || choice[i] > 57)
		{
			return ERROR;
		}
	}
	//若位数超过3位
	if (i > 3)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}
	int a = 0;
	a = atoi(choice);
	if (a < 0 || a>8)
	{
		return ERROR;
	}

	return SUCCESS;
}

//初始化链栈
Status initLStack(LinkStack* s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空 为空为SUCCESS 不为空为ERROR
Status isEmptyLStack(LinkStack* s)
{
	if (s->top == NULL)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空链栈
Status clearLStack(LinkStack* s)
{
	while (s->top != NULL)
	{
		StackNode* temp = s->top;
		s->top = temp->next;
		free(temp);
		temp = NULL;
	}
	s->count = 0;
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	while (s->top != NULL)
	{
		StackNode* temp = s->top;
		s->top = temp->next;
		free(temp);
		temp = NULL;
	}
	free(s);
	s = NULL;
	return SUCCESS;
}

//检测栈的长度
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL)
	{
		return ERROR;
	}
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	*data = s->top->data;
	StackNode* temp = s->top;
	s->top = temp->next;
	free(temp);
	temp = NULL;
	s->count--;
	return SUCCESS;
}

//遍历栈
void TraverseLStack(LinkStack* s)
{
	if (s->top == NULL)
	{
		printf("该链栈为空!\n");
		return;
	}
	printf("该链表存储数据为:\n");
	StackNode* temp = s->top;
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
	return;
}
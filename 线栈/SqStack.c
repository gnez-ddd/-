#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"

/*
typedef struct SqStack
{
	ElemType* elem;
	int top;
	int size;
} SqStack;
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

//初始化线栈
Status initStack(SqStack* s, int sizes)
{
	s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
	if (s->elem == NULL)
	{
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	return SUCCESS;
}

//判断栈是否为空 空为SUCCESS 不空为ERROR
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//得到栈顶元素
Status getTopStack(SqStack* s, ElemType* e)
{
	//该线栈为空
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;

}

//清空栈
Status clearStack(SqStack* s)
{
	//该链表本来就是空的
	if (s->top == -1)
	{
		return ERROR;
	}

	s->top = -1;
	return SUCCESS;

}

//销毁栈
Status destroyStack(SqStack* s)
{
	free(s->elem);
	s->elem = NULL;
	free(s);
	s = NULL;
	return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack* s, int* length)
{
	*length = s->top + 1;
	return SUCCESS;
}

//入栈
Status pushStack(SqStack* s, ElemType data)
{
	//判断栈是否满
	if (s->top == s->size - 1)
	{
		return ERROR;
	}

	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//出栈
Status popStack(SqStack* s, ElemType* data)
{
	//若栈为空
	if (s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
	
}

//遍历栈
void TraverseStack(SqStack* s)
{
	//若该线栈为空
	if (s->top == -1)
	{
		printf("该线栈为空!\n");
		return;
	}
	printf("该线栈存储数据为:\n");
	int i = 0;
	for (i = 0; i <= s->top; i++)
	{
		printf("%d\t", s->elem[i]);
	}
	printf("\n");
	return;
}
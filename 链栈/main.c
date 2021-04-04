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

int main()
{
	int judge = 0;
	char choice[100] = "1";
	int Choice = 1;

	//创建一个栈并初始化
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	if (s == NULL)
	{
		printf("分配内存失败，退出程序!\n");
		return 0;
	}
	initLStack(s);

	while (Choice != 0)
	{
		//打印主界面并选择功能
		printMenu();
		judge = funcChoice(choice);
		while (judge == 0)
		{
			printf("输入错误，请重新输入:\n");
			judge = funcChoice(choice);
		}
		Choice = atoi(choice);

		switch (Choice)
		{
			//退出系统
			case 0:
			{
				system("cls");
				printf("成功退出!\n");
				break;
			}

			//进栈Status pushLStack(LinkStack* s, ElemType data)
			case 1:
			{
				system("cls");
				printf("请输入要存放的数据:\n");
				int e = 0;
				e = dataJudge();
				judge=pushLStack(s, e);
				if (judge == ERROR)
				{
					printf("分配内存失败，无法插入,退出程序!\n");
					Choice = 0;
					break;
				}
				if (judge == SUCCESS)
				{
					printf("添加数据成功!\n");
					break;
				}

			}

			//出栈Status popLStack(LinkStack* s, ElemType* data)
			case 2:
			{
				system("cls");
				int e = 0;
				judge = popLStack(s, &e);
				if (judge == ERROR)
				{
					printf("该链栈为空，暂无数据!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("出栈成功!\n");
					printf("该数据为:%d\n", e);
					break;
				}
			}

			//判断栈是否为空Status isEmptyLStack(LinkStack* s)
			case 3:
			{
				system("cls");
				judge = isEmptyLStack(s);
				if (judge == ERROR)
				{
					printf("该链栈不为空!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("该链栈为空!\n");
					break;
				}
			}

			//得到栈顶元素Status getTopLStack(LinkStack* s, ElemType* e)
			case 4:
			{
				system("cls");
				int e = 0;
				judge = getTopLStack(s, &e);
				if (judge == ERROR)
				{
					printf("该链栈为空，暂无链栈数据!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("该栈顶数据为:%d\n", e);
					break;
				}
			}

			//清空栈Status clearLStack(LinkStack* s)
			case 5:
			{
				system("cls");
				clearLStack(s);
				printf("清空成功!\n");
				break;

			}


			//销毁线栈Status destroyLStack(LinkStack* s)
			case 6:
			{
				system("cls");
				destroyLStack(s);
				printf("销毁链栈并成功退出程序!\n");
				Choice = 0;
				break;
			}

			//检测栈的长度Status LStackLength(LinkStack* s, int* length)
			case 7:
			{
				system("cls");
				int length = 0;
				LStackLength(s, &length);
				printf("该链栈长度为%d\n", length);
				break;
			}

			//遍历栈void TraverseLStack(LinkStack* s)
			case 8:
			{
				system("cls");
				TraverseLStack(s);
				break;
			}


		}







	}
}
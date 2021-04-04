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


int main() {

	int judge = 0;
	char choice[100] = "1";
	int Choice = 1;

	//创建一个栈
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	if (s == NULL)
	{
		printf("分配内存失败，退出程序!\n");
		return 0;
	}
	
	//输入线栈大小
	printf("请输入线栈的大小:\n");
	int sizes = 0;
	sizes = dataJudge();

	//初始化线栈
	judge=initStack(s,sizes);
	if (judge == ERROR)
	{
		printf("初始化线栈失败，退出程序!\n");
		return 0;
	}

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

			//进栈 Status pushStack(SqStack* s, ElemType data)
			case 1:
			{
				system("cls");
				printf("请输入要存放的数据:\n");
				int e = 0;
				e = dataJudge();
				judge = pushStack(s, e);
				if (judge == ERROR)
				{
					printf("该线栈已满，无法再添加数据\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("添加数据成功!\n");
					break;
				}

			}

			//退栈 Status popStack(SqStack* s, ElemType* data)
			case 2:
			{
				system("cls");
				int e = 0;
				judge=popStack(s, &e);
				if (judge == ERROR)
				{
					printf("该线栈为空，暂无数据!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("出栈成功!\n");
					printf("该数据为：%d\n", e);
					break;
				}
			}


			//判断栈是否为空 Status isEmptyStack(SqStack* s)
			case 3:
			{
				system("cls");
				judge = isEmptyStack(s);
				if (judge == SUCCESS)
				{
					printf("该线栈为空!\n");
					break;
				}
				if (judge == ERROR)
				{
					printf("该线栈不为空!\n");
					break;
				}
			}


			//得到栈顶元素Status getTopStack(SqStack* s, ElemType* e)
			case 4:
			{
				system("cls");
				int e = 0;
				judge = getTopStack(s, &e);
				if (judge == ERROR)
				{
					printf("该线栈为空，暂无栈顶数据!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("该栈顶数据为：%d\n", e);
					break;
				}
			}

			//清空线栈Status clearStack(SqStack* s)
			case 5:
			{
				system("cls");
				judge = clearStack(s);
				if (judge == ERROR)
				{
					printf("该线栈原本就为空!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("清空成功!\n");
					break;
				}
			}


			//销毁栈Status destroyStack(SqStack* s)
			case 6:
			{
				system("cls");
				destroyStack(s);
				printf("销毁并成功退出程序!\n");
				Choice = 0;
				break;
			}

			//检测栈的长度Status stackLength(SqStack* s, int* length)
			case 7:
			{
				system("cls");
				int length = 0;
				stackLength(s, &length);
				printf("该线栈长度为%d\n", length);
				break;
			}

			//遍历栈void TraverseStack(SqStack* s)
			case 8:
			{
				system("cls");
				TraverseStack(s);
				break;
			}
		
		}
	}





}
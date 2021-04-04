#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"calculator.h"

int main()
{

	int judge = 0;
	char choice[100] = "1";
	int Choice = 1;

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
				printf("成功退出\n");
				break;
			}
			//计算
			case 1:
			{
				system("cls");
				char str[1000] = "\0";//输入的表达式
				char mexp[1000] = "\0";//分开的中缀表达式
				char bexp[1000] = "\0";//后缀表达式
				double ret = 0;
				printf("请输入表达式：\n");
				gets(str);
				judge = expressionJudge(str);
				while (judge == ERROR)
				{
					printf("输入有误，请重新输入：\n");
					gets(str);
					judge = expressionJudge(str);
				}

				//将表达式中的运算符与数字分开
				divideExpression(str, mexp);

				//将中缀表达式转换为后缀表达式
				judge = changeExp(mexp, bexp);
				if (judge == ERROR)
				{
					printf("分配内存失败，退出程序!\n");
					return 0;
				}

				//计算后缀表达式
				judge = figureExp(bexp, &ret);
				if (judge == 0)
				{
					printf("是傻逼吗？被除数不能为0\n");
					break;
				}
				printf("结果为%f\n", ret);
				break;
			}
		}
	}




	
	system("pause");
	return 0;



}
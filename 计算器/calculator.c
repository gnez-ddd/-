#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculator.h"

//判断中缀表达式是否符合要求
Status expressionJudge(char* str)
{
	unsigned int i = 0;
	//判断每一位是否符合表达式的要求
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i]!='.'&&str[i] != '-' && str[i] != '+' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')' && (str[i] < 47 || str[i]>58))
		{
			return ERROR;
		}
	}
	//表达式首位不能为）、*、/、.
	if (str[0] == ')' || str[0] == '*' || str[0] == '/'||str[0]=='.')
	{
		return ERROR;
	}
	//表达式末尾不能为（、*、/、+、-、.
	if (str[strlen(str) - 1] == '(' || str[strlen(str) - 1] == '*' || str[strlen(str) - 1] == '/' || str[strlen(str) - 1] == '+' || str[strlen(str) - 1] == '-'|| str[strlen(str) - 1] == '.')
	{
		return ERROR;
	}
	//创建一个栈
	operatorStack* s = (operatorStack*)malloc(sizeof(operatorStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	//表达式运算符不能连续同时括号必须成对
	for (i = 0; i < strlen(str); i++)
	{
		//判断括号是否符合要求
		//若为左括号则将左括号进栈
		if (str[i] == '(')
		{
			charpushStack(s, str[i]);
		}
		//若为右括号则将栈中左括号出栈，否则return
		if (str[i] == ')')
		{
			if (s->top == NULL)
			{
				return ERROR;
			}
			else
			{
				charpopLStack(s);
			}
		}
		//运算符不可以连续
		if (i != 0 && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && (str[i - 1] == '-' || str[i - 1] == '+' || str[i - 1] == '*' || str[i - 1] == '/'))
		{
			return ERROR;
		}
	}
	if (s->top != NULL)
	{
		return ERROR;
	}
	free(s);
	s = NULL;
	return SUCCESS;
}

//分隔中缀表达式的数字及运算符
void divideExpression(char* str,char* mexp)
{
	unsigned int i = 0, j = 0, count = 0, start = 0;
	char cut[1000]="\0";
	for (i = 0; i < strlen(str); i++)
	{
		//运到运算符就直接存入
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '('||str[i]==')')
		{
			mexp[j] = str[i];
			mexp[j + 1] = ' ';
			j+=2;
		}
		//遇到数字就一直读直到下一个为运算符
		if (str[i] > 47 && str[i] < 58)
		{
			count = 0;
			start = i;
			for (i; str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != '*' && str[i + 1] != '/' && str[i + 1] != '('&&str[i+1]!=')'&&i<strlen(str)-1; i++)
			{
				count++;
			}
			//如果最后一位位数字
			if (i == strlen(str))
			{
				if (str[i] > 47 && str[i] < 58)
				{
					count++;
					i++;
				}
			}
			count++;
			cutChar(str, start, count, cut);
			memcpy(&mexp[j], cut, strlen(cut));
			j = j + count;
			mexp[j] = ' ';
			j++;
		}
	}
	return;
}

//剪切字符串
void cutChar(char* str,int start,int count,char* cut)
{
	memcpy(cut, str,strlen(str));
	memcpy(cut, cut + start, strlen(cut) - start);
	memset(cut + count, '\0', strlen(cut) - count);
	return;
}

//将中缀表达式转化为后缀表达式
Status changeExp(char* mexp, char* bexp)
{
	//创建一个栈来对运算符进行操作
	operatorStack* s = (operatorStack*)malloc(sizeof(operatorStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	unsigned int i = 0,j = 0;
	for (i = 0; i < strlen(mexp); i++)
	{
		//如果是数字则直接进bexp
		if (mexp[i] != '+' && mexp[i] != '-' && mexp[i] != '*' && mexp[i] != '/' && mexp[i] != '('&&mexp[i]!=')'&&mexp[i]!=' ')
		{
			bexp[j] = mexp[i];
			j++;
		}
		//如果是空格直接进bexp
		if (mexp[i] ==' ')
		{
			bexp[j] = mexp[i];
			j++;
		}
		//如果是+，则判断
		if (mexp[i] == '+')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'||s->top->data=='+'||s->top->data=='-'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//如果是-，则判断
		if (mexp[i] == '-')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'||s->top->data=='+'||s->top->data=='-'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//如果是*,则判断
		if (mexp[i] == '*')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//如果是/
		if (mexp[i] == '/')
		{
			while (s->top!=NULL&&(s->top->data == '/' || s->top->data == '*'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//如果是（
		if (mexp[i] == '(')
		{
			charpushStack(s, mexp[i]);
		}
		//如果是)
		if (mexp[i] == ')')
		{
			while (s->top!=NULL&&s->top->data != '(')
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpopLStack(s);
		}
	}
	//将栈中符合全部弹除
	while (s->top != NULL)
	{
		charpopLStackShow(s, &bexp[j]);
		bexp[j + 1] = ' ';
		j += 2;
	}
	free(s);
	s = NULL;
	return SUCCESS;
}

//计算
double figure(double num1, double num2, char* operator)
{
	if (*operator=='+')
	{
		return num1 + num2;
	}
	if (*operator=='-')
	{
		return num1 - num2;
	}
	if (*operator=='*')
	{
		return num1 * num2;
	}
	if (*operator=='/')
	{
		return num1 / num2;
	}
	return 0;
}

//计算后缀表达式
Status figureExp(char* bexp,double* ret)
{
	int count = 0,start=0;
	char cut[1000] = "\0";
	double num = 0;
	double num1 = 0;
	double num2 = 0;
	//创建一个栈来对数字进行操作
	numStack* s = (numStack*)malloc(sizeof(numStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	unsigned int i = 0;
	for (i = 0; i < strlen(bexp); i++)
	{
		//若为数字转换格式后则进栈
		if (bexp[i] != '+' && bexp[i] != '-' && bexp[i] != '*' && bexp[i] != '/'&&bexp[i]!=' ')
		{
			count = 0;
			start = i;
			for (i; bexp[i + 1] != '+' && bexp[i + 1] != '-' && bexp[i + 1] != '*' && bexp[i + 1] != '/' &&bexp[i+1]!=' '&& i < strlen(bexp) - 1; i++)
			{
				count++;
			}
			//如果最后一位位数字
			if (i == strlen(bexp))
			{
				if (bexp[i] > 47 && bexp[i] < 58)
				{
					count++;
					i++;
				}
			}
			count++;
			cutChar(bexp, start, count, cut);
			num = atof(cut);
			numpushStack(s,num);
		}
		//如果为运算符
		if (bexp[i] == '-' || bexp[i] == '+' || bexp[i] == '*')
		{
			numpopLStackShow(s, &num2);
			numpopLStackShow(s, &num1);
			num = figure(num1, num2, &bexp[i]);
			numpushStack(s, num);
		}
		if (bexp[i] == '/')
		{
			numpopLStackShow(s, &num2);
			if (num2 == 0)
			{
				free(s);
				s = NULL;
				return ERROR;
			}
			numpopLStackShow(s, &num1);
			num = figure(num1, num2, &bexp[i]);
			numpushStack(s, num);
		}
	}
	numpopLStackShow(s, ret);
	free(s);
	s = NULL;
	return SUCCESS;

}

//字符串进栈
Status charpushStack(operatorStack* s, ElemType data)
{
	operatorStackNode* newNode = (operatorStackNode*)malloc(sizeof(operatorStackNode));
	if (newNode == NULL)
	{
		return ERROR;
	}
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	return SUCCESS;
}

//字符串出栈
Status charpopLStack(operatorStack* s)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	operatorStackNode* temp = s->top;
	s->top = temp->next;
	free(temp);
	temp = NULL;
	return SUCCESS;
}

//字符串出栈并显示该数据
Status charpopLStackShow(operatorStack* s, ElemType* data)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	*data = s->top->data;
	operatorStackNode* temp = s->top;
	s->top = temp->next;
	free(temp);
	temp = NULL;
	return SUCCESS;
}

//数字进栈
Status numpushStack(numStack* s, double data)
{
	numStackNode* newNode = (numStackNode*)malloc(sizeof(numStackNode));
	if (newNode == NULL)
	{
		return ERROR;
	}
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	return SUCCESS;
}

//数字出栈并显示数据
Status numpopLStackShow(numStack* s, double* data)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	*data = s->top->data;
	numStackNode* temp = s->top;
	s->top = temp->next;
	free(temp);
	temp = NULL;
	return SUCCESS;

}

//判断栈是否为空 为空为SUCCESS 不为空为ERROR
Status isEmptyLStack(operatorStack* s)
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

//打印菜单
void printMenu()
{
	printf("hahahahahahahahahahahaha\n");
	printf("======1.计算     =======\n");
	printf("======0.退出     =======\n");
	printf("请输入想要的功能:\n");
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
	if (a < 0 || a>1)
	{
		return ERROR;
	}

	return SUCCESS;
}
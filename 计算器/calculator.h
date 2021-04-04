#pragma once
#ifndef CALCULTOR_H_INCLUDE
#define CALCULTOR_H_INCLUDE

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
}Status;

typedef char ElemType;

//运算符栈节点
typedef struct operatorStackNode
{
	ElemType data;
	struct operatorStackNode* next;
}operatorStackNode;

//数字节点
typedef struct numStackNode
{
	double data;
	struct numStackNode* next;
}numStackNode;

//数字栈
typedef struct numStack
{
	numStackNode* top;
}numStack;

//运算符栈
typedef struct operatorStack
{
	operatorStackNode* top;
}operatorStack;

//判断中缀表达式是否符合要求
Status expressionJudge(char* str);

//分隔中缀表达式的数字及运算符
void divideExpression(char* str, char* mexp);

//剪切字符串
void cutChar(char* str, int start, int count, char* cut);

//将中缀表达式转化为后缀表达式
Status changeExp(char* mexp, char* bexp);

//计算
double figure(double num1, double num2, char* operator);

//计算后缀表达式
Status figureExp(char* bexp, double* ret);

//字符串进栈
Status charpushStack(operatorStack* s, ElemType data);

//字符串出栈
Status charpopLStack(operatorStack* s);

//字符串出栈并显示该数据
Status charpopLStackShow(operatorStack* s, ElemType* data);

//数字进栈
Status numpushStack(numStack* s, double data);

//数字出栈并显示数据
Status numpopLStackShow(numStack* s, double* data);

//判断栈是否为空 为空为SUCCESS 不为空为ERROR
Status isEmptyLStack(operatorStack* s);

//选择功能
Status funcChoice(char* choice);

//打印菜单
void printMenu();

#endif



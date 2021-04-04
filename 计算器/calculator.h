#pragma once
#ifndef CALCULTOR_H_INCLUDE
#define CALCULTOR_H_INCLUDE

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
}Status;

typedef char ElemType;

//�����ջ�ڵ�
typedef struct operatorStackNode
{
	ElemType data;
	struct operatorStackNode* next;
}operatorStackNode;

//���ֽڵ�
typedef struct numStackNode
{
	double data;
	struct numStackNode* next;
}numStackNode;

//����ջ
typedef struct numStack
{
	numStackNode* top;
}numStack;

//�����ջ
typedef struct operatorStack
{
	operatorStackNode* top;
}operatorStack;

//�ж���׺���ʽ�Ƿ����Ҫ��
Status expressionJudge(char* str);

//�ָ���׺���ʽ�����ּ������
void divideExpression(char* str, char* mexp);

//�����ַ���
void cutChar(char* str, int start, int count, char* cut);

//����׺���ʽת��Ϊ��׺���ʽ
Status changeExp(char* mexp, char* bexp);

//����
double figure(double num1, double num2, char* operator);

//�����׺���ʽ
Status figureExp(char* bexp, double* ret);

//�ַ�����ջ
Status charpushStack(operatorStack* s, ElemType data);

//�ַ�����ջ
Status charpopLStack(operatorStack* s);

//�ַ�����ջ����ʾ������
Status charpopLStackShow(operatorStack* s, ElemType* data);

//���ֽ�ջ
Status numpushStack(numStack* s, double data);

//���ֳ�ջ����ʾ����
Status numpopLStackShow(numStack* s, double* data);

//�ж�ջ�Ƿ�Ϊ�� Ϊ��ΪSUCCESS ��Ϊ��ΪERROR
Status isEmptyLStack(operatorStack* s);

//ѡ����
Status funcChoice(char* choice);

//��ӡ�˵�
void printMenu();

#endif



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

//��ӡ�˵�
void printMenu()
{
	printf("==========hahahahahahahah          ==========\n");
	printf("==========1.��ջ                   ==========\n");
	printf("==========2.��ջ                   ==========\n");
	printf("==========3.�ж�ջ�Ƿ�Ϊ��         ==========\n");
	printf("==========4.�õ�ջ��Ԫ��           ==========\n");
	printf("==========5.���ջ                 ==========\n");
	printf("==========6.����ջ���˳�����       ==========\n");
	printf("==========7.���ջ�ĳ���           ==========\n");
	printf("==========8.����ջ                 ==========\n");
	printf("==========0.�˳�                   ==========\n");
	printf("�����빦�ܵĶ�Ӧ���:\n");
}

//���������ж�
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
	//ͨ����ѭ��˵��ȫ����������
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] < 48 || a[i] > 57)
		{

			return ERROR;
		}
	}
	//��λ������11λ
	if (i > 11)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}

	return SUCCESS;
}

//��������
int dataJudge()
{
	int d = 0;
	char a[100];
	int ret = 0;
	ret = charJudge(a);
	while (ret == 0)
	{
		printf("�����������������룺\n");
		ret = charJudge(a);
	}
	d = atoi(a);
	return d;
}

//ѡ����
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
	//ͨ����ѭ��˵��ȫ����������
	for (i = 0; choice[i] != '\0'; i++)
	{
		if (choice[i] < 48 || choice[i] > 57)
		{
			return ERROR;
		}
	}
	//��λ������3λ
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

//��ʼ����ջ
Status initLStack(LinkStack* s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ�� Ϊ��ΪSUCCESS ��Ϊ��ΪERROR
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

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s->top == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//�����ջ
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

//����ջ
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

//���ջ�ĳ���
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;
	return SUCCESS;
}

//��ջ
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

//��ջ
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

//����ջ
void TraverseLStack(LinkStack* s)
{
	if (s->top == NULL)
	{
		printf("����ջΪ��!\n");
		return;
	}
	printf("������洢����Ϊ:\n");
	StackNode* temp = s->top;
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
	return;
}
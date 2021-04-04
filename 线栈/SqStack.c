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

//�ж�ջ�Ƿ�Ϊ�� ��ΪSUCCESS ����ΪERROR
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

//�õ�ջ��Ԫ��
Status getTopStack(SqStack* s, ElemType* e)
{
	//����ջΪ��
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;

}

//���ջ
Status clearStack(SqStack* s)
{
	//�����������ǿյ�
	if (s->top == -1)
	{
		return ERROR;
	}

	s->top = -1;
	return SUCCESS;

}

//����ջ
Status destroyStack(SqStack* s)
{
	free(s->elem);
	s->elem = NULL;
	free(s);
	s = NULL;
	return SUCCESS;
}

//���ջ����
Status stackLength(SqStack* s, int* length)
{
	*length = s->top + 1;
	return SUCCESS;
}

//��ջ
Status pushStack(SqStack* s, ElemType data)
{
	//�ж�ջ�Ƿ���
	if (s->top == s->size - 1)
	{
		return ERROR;
	}

	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack* s, ElemType* data)
{
	//��ջΪ��
	if (s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
	
}

//����ջ
void TraverseStack(SqStack* s)
{
	//������ջΪ��
	if (s->top == -1)
	{
		printf("����ջΪ��!\n");
		return;
	}
	printf("����ջ�洢����Ϊ:\n");
	int i = 0;
	for (i = 0; i <= s->top; i++)
	{
		printf("%d\t", s->elem[i]);
	}
	printf("\n");
	return;
}
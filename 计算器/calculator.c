#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculator.h"

//�ж���׺���ʽ�Ƿ����Ҫ��
Status expressionJudge(char* str)
{
	unsigned int i = 0;
	//�ж�ÿһλ�Ƿ���ϱ��ʽ��Ҫ��
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i]!='.'&&str[i] != '-' && str[i] != '+' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')' && (str[i] < 47 || str[i]>58))
		{
			return ERROR;
		}
	}
	//���ʽ��λ����Ϊ����*��/��.
	if (str[0] == ')' || str[0] == '*' || str[0] == '/'||str[0]=='.')
	{
		return ERROR;
	}
	//���ʽĩβ����Ϊ����*��/��+��-��.
	if (str[strlen(str) - 1] == '(' || str[strlen(str) - 1] == '*' || str[strlen(str) - 1] == '/' || str[strlen(str) - 1] == '+' || str[strlen(str) - 1] == '-'|| str[strlen(str) - 1] == '.')
	{
		return ERROR;
	}
	//����һ��ջ
	operatorStack* s = (operatorStack*)malloc(sizeof(operatorStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	//���ʽ�������������ͬʱ���ű���ɶ�
	for (i = 0; i < strlen(str); i++)
	{
		//�ж������Ƿ����Ҫ��
		//��Ϊ�������������Ž�ջ
		if (str[i] == '(')
		{
			charpushStack(s, str[i]);
		}
		//��Ϊ��������ջ�������ų�ջ������return
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
		//���������������
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

//�ָ���׺���ʽ�����ּ������
void divideExpression(char* str,char* mexp)
{
	unsigned int i = 0, j = 0, count = 0, start = 0;
	char cut[1000]="\0";
	for (i = 0; i < strlen(str); i++)
	{
		//�˵��������ֱ�Ӵ���
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '('||str[i]==')')
		{
			mexp[j] = str[i];
			mexp[j + 1] = ' ';
			j+=2;
		}
		//�������־�һֱ��ֱ����һ��Ϊ�����
		if (str[i] > 47 && str[i] < 58)
		{
			count = 0;
			start = i;
			for (i; str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != '*' && str[i + 1] != '/' && str[i + 1] != '('&&str[i+1]!=')'&&i<strlen(str)-1; i++)
			{
				count++;
			}
			//������һλλ����
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

//�����ַ���
void cutChar(char* str,int start,int count,char* cut)
{
	memcpy(cut, str,strlen(str));
	memcpy(cut, cut + start, strlen(cut) - start);
	memset(cut + count, '\0', strlen(cut) - count);
	return;
}

//����׺���ʽת��Ϊ��׺���ʽ
Status changeExp(char* mexp, char* bexp)
{
	//����һ��ջ������������в���
	operatorStack* s = (operatorStack*)malloc(sizeof(operatorStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	unsigned int i = 0,j = 0;
	for (i = 0; i < strlen(mexp); i++)
	{
		//�����������ֱ�ӽ�bexp
		if (mexp[i] != '+' && mexp[i] != '-' && mexp[i] != '*' && mexp[i] != '/' && mexp[i] != '('&&mexp[i]!=')'&&mexp[i]!=' ')
		{
			bexp[j] = mexp[i];
			j++;
		}
		//����ǿո�ֱ�ӽ�bexp
		if (mexp[i] ==' ')
		{
			bexp[j] = mexp[i];
			j++;
		}
		//�����+�����ж�
		if (mexp[i] == '+')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'||s->top->data=='+'||s->top->data=='-'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//�����-�����ж�
		if (mexp[i] == '-')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'||s->top->data=='+'||s->top->data=='-'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//�����*,���ж�
		if (mexp[i] == '*')
		{
			while (s->top!=NULL&&(s->top->data == '*' || s->top->data == '/'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//�����/
		if (mexp[i] == '/')
		{
			while (s->top!=NULL&&(s->top->data == '/' || s->top->data == '*'))
			{
				charpopLStackShow(s, &bexp[j]);
				j++;
			}
			charpushStack(s, mexp[i]);
		}
		//����ǣ�
		if (mexp[i] == '(')
		{
			charpushStack(s, mexp[i]);
		}
		//�����)
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
	//��ջ�з���ȫ������
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

//����
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

//�����׺���ʽ
Status figureExp(char* bexp,double* ret)
{
	int count = 0,start=0;
	char cut[1000] = "\0";
	double num = 0;
	double num1 = 0;
	double num2 = 0;
	//����һ��ջ�������ֽ��в���
	numStack* s = (numStack*)malloc(sizeof(numStack));
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	unsigned int i = 0;
	for (i = 0; i < strlen(bexp); i++)
	{
		//��Ϊ����ת����ʽ�����ջ
		if (bexp[i] != '+' && bexp[i] != '-' && bexp[i] != '*' && bexp[i] != '/'&&bexp[i]!=' ')
		{
			count = 0;
			start = i;
			for (i; bexp[i + 1] != '+' && bexp[i + 1] != '-' && bexp[i + 1] != '*' && bexp[i + 1] != '/' &&bexp[i+1]!=' '&& i < strlen(bexp) - 1; i++)
			{
				count++;
			}
			//������һλλ����
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
		//���Ϊ�����
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

//�ַ�����ջ
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

//�ַ�����ջ
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

//�ַ�����ջ����ʾ������
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

//���ֽ�ջ
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

//���ֳ�ջ����ʾ����
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

//�ж�ջ�Ƿ�Ϊ�� Ϊ��ΪSUCCESS ��Ϊ��ΪERROR
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

//��ӡ�˵�
void printMenu()
{
	printf("hahahahahahahahahahahaha\n");
	printf("======1.����     =======\n");
	printf("======0.�˳�     =======\n");
	printf("��������Ҫ�Ĺ���:\n");
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
	if (a < 0 || a>1)
	{
		return ERROR;
	}

	return SUCCESS;
}
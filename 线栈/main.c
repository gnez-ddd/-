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

	//����һ��ջ
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	if (s == NULL)
	{
		printf("�����ڴ�ʧ�ܣ��˳�����!\n");
		return 0;
	}
	
	//������ջ��С
	printf("��������ջ�Ĵ�С:\n");
	int sizes = 0;
	sizes = dataJudge();

	//��ʼ����ջ
	judge=initStack(s,sizes);
	if (judge == ERROR)
	{
		printf("��ʼ����ջʧ�ܣ��˳�����!\n");
		return 0;
	}

	while (Choice != 0)
	{
		//��ӡ�����沢ѡ����
		printMenu();
		judge = funcChoice(choice);
		while (judge == 0)
		{
			printf("�����������������:\n");
			judge = funcChoice(choice);
		}
		Choice = atoi(choice);

		switch (Choice)
		{
			//�˳�ϵͳ
			case 0:
			{
				system("cls");
				printf("�ɹ��˳�!\n");
				break;
			}

			//��ջ Status pushStack(SqStack* s, ElemType data)
			case 1:
			{
				system("cls");
				printf("������Ҫ��ŵ�����:\n");
				int e = 0;
				e = dataJudge();
				judge = pushStack(s, e);
				if (judge == ERROR)
				{
					printf("����ջ�������޷����������\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("������ݳɹ�!\n");
					break;
				}

			}

			//��ջ Status popStack(SqStack* s, ElemType* data)
			case 2:
			{
				system("cls");
				int e = 0;
				judge=popStack(s, &e);
				if (judge == ERROR)
				{
					printf("����ջΪ�գ���������!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("��ջ�ɹ�!\n");
					printf("������Ϊ��%d\n", e);
					break;
				}
			}


			//�ж�ջ�Ƿ�Ϊ�� Status isEmptyStack(SqStack* s)
			case 3:
			{
				system("cls");
				judge = isEmptyStack(s);
				if (judge == SUCCESS)
				{
					printf("����ջΪ��!\n");
					break;
				}
				if (judge == ERROR)
				{
					printf("����ջ��Ϊ��!\n");
					break;
				}
			}


			//�õ�ջ��Ԫ��Status getTopStack(SqStack* s, ElemType* e)
			case 4:
			{
				system("cls");
				int e = 0;
				judge = getTopStack(s, &e);
				if (judge == ERROR)
				{
					printf("����ջΪ�գ�����ջ������!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("��ջ������Ϊ��%d\n", e);
					break;
				}
			}

			//�����ջStatus clearStack(SqStack* s)
			case 5:
			{
				system("cls");
				judge = clearStack(s);
				if (judge == ERROR)
				{
					printf("����ջԭ����Ϊ��!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("��ճɹ�!\n");
					break;
				}
			}


			//����ջStatus destroyStack(SqStack* s)
			case 6:
			{
				system("cls");
				destroyStack(s);
				printf("���ٲ��ɹ��˳�����!\n");
				Choice = 0;
				break;
			}

			//���ջ�ĳ���Status stackLength(SqStack* s, int* length)
			case 7:
			{
				system("cls");
				int length = 0;
				stackLength(s, &length);
				printf("����ջ����Ϊ%d\n", length);
				break;
			}

			//����ջvoid TraverseStack(SqStack* s)
			case 8:
			{
				system("cls");
				TraverseStack(s);
				break;
			}
		
		}
	}





}
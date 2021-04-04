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

	//����һ��ջ����ʼ��
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	if (s == NULL)
	{
		printf("�����ڴ�ʧ�ܣ��˳�����!\n");
		return 0;
	}
	initLStack(s);

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

			//��ջStatus pushLStack(LinkStack* s, ElemType data)
			case 1:
			{
				system("cls");
				printf("������Ҫ��ŵ�����:\n");
				int e = 0;
				e = dataJudge();
				judge=pushLStack(s, e);
				if (judge == ERROR)
				{
					printf("�����ڴ�ʧ�ܣ��޷�����,�˳�����!\n");
					Choice = 0;
					break;
				}
				if (judge == SUCCESS)
				{
					printf("������ݳɹ�!\n");
					break;
				}

			}

			//��ջStatus popLStack(LinkStack* s, ElemType* data)
			case 2:
			{
				system("cls");
				int e = 0;
				judge = popLStack(s, &e);
				if (judge == ERROR)
				{
					printf("����ջΪ�գ���������!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("��ջ�ɹ�!\n");
					printf("������Ϊ:%d\n", e);
					break;
				}
			}

			//�ж�ջ�Ƿ�Ϊ��Status isEmptyLStack(LinkStack* s)
			case 3:
			{
				system("cls");
				judge = isEmptyLStack(s);
				if (judge == ERROR)
				{
					printf("����ջ��Ϊ��!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("����ջΪ��!\n");
					break;
				}
			}

			//�õ�ջ��Ԫ��Status getTopLStack(LinkStack* s, ElemType* e)
			case 4:
			{
				system("cls");
				int e = 0;
				judge = getTopLStack(s, &e);
				if (judge == ERROR)
				{
					printf("����ջΪ�գ�������ջ����!\n");
					break;
				}
				if (judge == SUCCESS)
				{
					printf("��ջ������Ϊ:%d\n", e);
					break;
				}
			}

			//���ջStatus clearLStack(LinkStack* s)
			case 5:
			{
				system("cls");
				clearLStack(s);
				printf("��ճɹ�!\n");
				break;

			}


			//������ջStatus destroyLStack(LinkStack* s)
			case 6:
			{
				system("cls");
				destroyLStack(s);
				printf("������ջ���ɹ��˳�����!\n");
				Choice = 0;
				break;
			}

			//���ջ�ĳ���Status LStackLength(LinkStack* s, int* length)
			case 7:
			{
				system("cls");
				int length = 0;
				LStackLength(s, &length);
				printf("����ջ����Ϊ%d\n", length);
				break;
			}

			//����ջvoid TraverseLStack(LinkStack* s)
			case 8:
			{
				system("cls");
				TraverseLStack(s);
				break;
			}


		}







	}
}
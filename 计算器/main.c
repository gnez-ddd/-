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
				printf("�ɹ��˳�\n");
				break;
			}
			//����
			case 1:
			{
				system("cls");
				char str[1000] = "\0";//����ı��ʽ
				char mexp[1000] = "\0";//�ֿ�����׺���ʽ
				char bexp[1000] = "\0";//��׺���ʽ
				double ret = 0;
				printf("��������ʽ��\n");
				gets(str);
				judge = expressionJudge(str);
				while (judge == ERROR)
				{
					printf("�����������������룺\n");
					gets(str);
					judge = expressionJudge(str);
				}

				//�����ʽ�е�����������ַֿ�
				divideExpression(str, mexp);

				//����׺���ʽת��Ϊ��׺���ʽ
				judge = changeExp(mexp, bexp);
				if (judge == ERROR)
				{
					printf("�����ڴ�ʧ�ܣ��˳�����!\n");
					return 0;
				}

				//�����׺���ʽ
				judge = figureExp(bexp, &ret);
				if (judge == 0)
				{
					printf("��ɵ���𣿱���������Ϊ0\n");
					break;
				}
				printf("���Ϊ%f\n", ret);
				break;
			}
		}
	}




	
	system("pause");
	return 0;



}
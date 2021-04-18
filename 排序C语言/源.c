#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"qgsort.h"

clock_t start, stop;
double duration;

int main()
{
	int judge = 0;
	char choice[100] = "1";
	int Choice = 1;

	while (Choice != 0)
	{
		//��ӡ�����沢ѡ����
		menuPrintf();
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
				printf("�ɹ��˳���\n");
				break;
			}

			//������������ʱ
			case 1:
			{
				
				system("cls");
				int i = 0;
				printf("��������������\n");
				int size = 0;
				size = intJudge();
				int* A = (int*)malloc(sizeof(int) * size);
				if (A == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(A, 0, sizeof(int) * size);
				getRandomNum(A, size);
				int* a = (int*)malloc(sizeof(int) * size);
				if (a == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * size);
				int* Temp = (int*)malloc(sizeof(int) * size);
				if (Temp == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * size);
				
				//���Բ��������㷨
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				insertSort(a, size);
				stop = clock();
				duration = ((double)stop-(double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);
				
				//���Թ鲢����
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				MergeSort(a, 0, size - 1, Temp);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�鲢�����㷨����ʱ��Ϊ��%lfs\n", duration);

				
				//���Կ�������ݹ��
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				QuickSort_Recursion(a, 0, size - 1);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("��������ݹ鷨�㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Կ�������ǵݹ��
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				QuickSort(a, size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("��������ǵݹ鷨�㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Լ�������
				memcpy(a, A, sizeof(int) * size);
				int max = 0,min=0;
				MaxAndMin(a, &max, &min, size);
				start = clock();
				CountSort(a, size, max,min);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Ի�������
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				RadixCountSort(a, size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);
				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				break;
			}

			//����С��������ʱ
			case 2:
			{
				system("cls");
				int* A = (int*)malloc(sizeof(int) * 100);
				if (A == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(A, 0, sizeof(int) * 100);
				getRandomNum(A, 100);
				int* a = (int*)malloc(sizeof(int) * 100);
				if (a == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * 100);
				int* Temp = (int*)malloc(sizeof(int) * 100);
				if (Temp == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * 100);
				int i = 0;
				//���Բ��������㷨
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int)* 100);
					insertSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Թ鲢�����㷨
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					MergeSort(a, 0, 99, Temp);
					memset(Temp, 0, sizeof(int) * 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�鲢�����㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Կ��ŵݹ������㷨
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					QuickSort_Recursion(a, 0, 99);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���ŵݹ������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Կ��ŷǵݹ������㷨
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					QuickSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���ŷǵݹ������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Լ��������㷨
				start = clock();
				int max = 0, min = 0;
				MaxAndMin(a, &max, &min, 100);
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					CountSort(a, 100, max, min);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Ի��������㷨
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					RadixCountSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				break;

			}

			//��ɫ����
			case 3:
			{
				system("cls");
				int i = 0;
				printf("��������������\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				srand((int)time(0));
				i = 0;
				for (i = 0; i < size; i++)
				{
					a[i] = rand() %3+0;
				}
				printf("����ǰ��\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
				ColorSort(a, size);
				printf("�����\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n");
				free(a);
				if (a != NULL)
				{
					a = NULL;
				}
				break;
			}

			//Ѱ�ҵ�k�����
			case 4:
			{
				system("cls");
				int i = 0;
				printf("��������������\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				getRandomNum(a, size);
				printf("��������Ϊ��\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n������ҪѰ�ҵĵڼ������ݣ�");
				int k = 0;
				k = intJudge();
				while (k > size || k <= 0)
				{
					printf("�����������������룡\n");
					k = intJudge();
				}
				int num = 0;
				num = getNum(a, size, k);
				printf("������Ϊ��%d\n", num);
				free(a);
				a = NULL;
				break;

			}

			//�������ݲ����浽�ļ���
			case 5:
			{
				char path[100] = "\0";
				printf("�������ļ�·��:\n");
				gets(path);
				printf("��������������\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				getRandomNum(a, size);
				storenumFile(a, path, size);
				break;

			}

			//��ȡ���ݲ�����
			case 6:
			{
				int Size = 0;
				char path[100] = "\0";
				printf("�������ļ�·��:\n");
				gets(path);
				int* Ret=readNumFild(path,&Size);
				if (Ret == NULL)
				{
					printf("��ȡ����ʧ�ܣ�\n");
					break;
				}
				int i = 0;
				printf("���ļ�������Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", Ret[i]);
				}
				printf("\n");
				
				int* A = (int*)malloc(sizeof(int) * Size);
				if (A == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memcpy(A, Ret, sizeof(int) * Size);
				int* a = (int*)malloc(sizeof(int) * Size);
				if (a == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * Size);
				int* Temp = (int*)malloc(sizeof(int) * Size);
				if (Temp == NULL)
				{
					printf("�����ڴ�ʧ�ܣ��˳�ϵͳ��\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * Size);

				//���Բ��������㷨
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				insertSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Թ鲢����
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				MergeSort(a, 0, Size - 1, Temp);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("�鲢�����㷨����ʱ��Ϊ��%lfs\n", duration);


				//���Կ�������ݹ��
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				QuickSort_Recursion(a, 0, Size - 1);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("��������ݹ鷨�㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Կ�������ǵݹ��
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				QuickSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("��������ǵݹ鷨�㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Լ�������
				memcpy(a, A, sizeof(int) * Size);
				int max = 0, min = 0;
				MaxAndMin(a, &max, &min, Size);
				start = clock();
				CountSort(a, Size, max, min);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);

				//���Ի�������
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				RadixCountSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("�����Ϊ��\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("���������㷨����ʱ��Ϊ��%lfs\n", duration);
				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				free(Ret);
				Ret = NULL;


				break;
			}

		}

	}
	return 0;
}